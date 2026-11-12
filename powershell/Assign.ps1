function Get-SystemInfo {
    #First, I will get hostname.
    Write-Host "Hostname: $env:COMPUTERNAME"
    #Second, I will get OS version
    Get-ComputerInfo -Propery OSVersion
    #Third, we can get uptime
    Get-Uptime
}
function Manage-UserAccounts {
    #Var to keep us in the menu until user exits.
    $stayLooping = $true
    #Menu will keep running in a while loop until user exits.
    while ($stayLooping) {
        $choice = Read-Host "Please Select an option. 1 to list all local accounts, 2 to add a new user, 3 to delete a user, and 4 to exit."
        switch ($choice) {
            1 { Get-LocalUser }
            2 {
                #I modeled this after Microsoft's documentation, but adjusted to my needs.
                $userName = Read-Host "Please enter a username."
                $password = Read-Host -AsSecureString "Please enter a password"
                $params = @{
                    Name     = $userName
                    Password = $password
                }
                New-LocalUser @params
            }
            3 {
                #Here is where we disable a user. If command returns user, it will delete them.
                $DisableUser = Read-Host "Please enter a user to delete."
                if (Get-LocalUser -Name $DisableUser -ErrorAction SilentlyContinue) {
                    Disable-LocalUser -Name $DisableUser
                }
                else {
                    Write-Host "User does not exist."
                }
            }
            4 {
                $stayLooping = $false
            }
            default {
                Write-Host "Invalid input, please select a number 1-4."
            }
        }
    }
}
function Clean-TempFiles {
    $path = "C:\Temp"
    $log = "$env:USERPROFILE\cleanup.log"
    $total = 0

    $choice = Read-Host "Delete everything inside C:\Temp? (y/n)"
    if ($choice -ne 'y') { return }

    if (-not (Test-Path -LiteralPath $path)) {
        Write-Host "Directory does not exist."
        return
    }

    Get-ChildItem -LiteralPath $path -Force | ForEach-Object {
        $item = $_

        #Calculate size before deletion
        $size = (Get-ChildItem -LiteralPath $item.FullName -File -Recurse -Force -ErrorAction Stop |
            Measure-Object -Property Length -Sum).Sum

        try {
            Remove-Item -LiteralPath $item.FullName -Recurse -Force -ErrorAction Stop

            $total += $size
            "$(Get-Date) Deleted: $($item.FullName)" |
            Out-File $log -Append
        }
        catch {
            "$(Get-Date) Failed: $($item.FullName) - $_" |
            Out-File $log -Append
        }
    }

    $mb = [math]::Round($total / 1MB, 2)
    Write-Host "Space cleared: $mb MB"
    "Total space cleared: $mb MB" | Out-File $log -Append
}
function Test-NetworkConnection {
    $stayLooping = $true
    while ($stayLooping) {
        $choice = Read-Host "Select 1 to list all NICs and IPs, select 2 to ping an address, 3 to exit"
        switch ($choice) {
            1 { ipconfig /all }
            2 {
                $unscsfl = $true
                $tries = 0
                $addr = Read-Host "Enter a Hostname or IP to ping"
                while ($unscsfl -eq $true -and $tries -le 3) {
                    if (Test-Connection -TargetName $addr -Count 1 -Quiet) {
                        Write-Host "Ping Success."
                        $unscsfl = $false
                    }
                    else {
                        Write-Host "Ping Failed."
                        $tries += 1
                    }
                }
            }
            3 {
                $stayLooping = $false
                return
            }
            default {
                Write-Host "Input not recognized, please try again."
            }
        }
    }

}
function Backup-Files {
    #Define source, destination, and log locations.
    $source = "C:\ImportantData"
    $destination = "C:\Backup"
    $log = "$env:USERPROFILE\backup.log"

    #Verify source exists.
    if (-not (Test-Path $source)) {
        Write-Host "Source folder does not exist."
        return
    }

    #Create destination if it doesn't exist.
    if (-not (Test-Path $destination)) {
        New-Item -ItemType Directory -Path $destination -Force
    }

    #Copy files and preserve subdirectories.
    Get-ChildItem -Path $source -File -Recurse | ForEach-Object {
        try {
            $relativePath = $_.FullName.Substring($source.Length)
            $target = Join-Path $destination $relativePath
            $targetFolder = Split-Path $target -Parent

            #Create subdirectory if necessary.
            New-Item -ItemType Directory -Path $targetFolder -Force |
                Out-Null

            Copy-Item -LiteralPath $_.FullName -Destination $target -Force -ErrorAction Stop

            # Log successful copy.
            "$(Get-Date) Copied: $($_.FullName) to $target" |
                Out-File $log -Append
        }
        catch {
            # Log errors.
            "$(Get-Date) ERROR: $_" |
                Out-File $log -Append
        }
    }

    Write-Host "Backup completed. Check $log for details."
}
# Main menu for PowerShell Administration Toolkit
$stayLooping = $true

while ($stayLooping) {
    Write-Host "`n===== PowerShell Administration Toolkit ====="
    Write-Host "1. Get System Information"
    Write-Host "2. Manage User Accounts"
    Write-Host "3. Clean Temporary Files"
    Write-Host "4. Test Network Connection"
    Write-Host "5. Backup Files"
    Write-Host "6. Exit"

    $choice = Read-Host "Please select an option (1-6)"

    switch ($choice) {
        '1' {
            Get-SystemInfo
        }
        '2' {
            Manage-UserAccounts
        }
        '3' {
            Clean-TempFiles
        }
        '4' {
            Test-NetworkConnection
        }
        '5' {
            Backup-Files
        }
        '6' {
            Write-Host "Exiting PowerShell Administration Toolkit."
            $stayLooping = $false
        }
        default {
            Write-Host "Invalid input. Please select a number between 1 and 6."
        }
    }
}
