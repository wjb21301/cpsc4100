function Get-SystemInfo{
    #First, I will get hostname.
    Write-Host "Hostname: $env:COMPUTERNAME"
    #Second, I will get OS version
    Get-ComputerInfo -Propery OSVersion
    #Third, we can get uptime
    Get-Uptime
}
function Manage-UserAccounts{
    #Var to keep us in the menu until user exits.
    $stayLooping = $true
    #Menu will keep running in a while loop until user exits.
    while ($stayLooping){
        $choice = Read-Host "Please Select an option. 1 to list all local accounts, 2 to add a new user, 3 to delete a user, and 4 to exit."
        switch ($choice) {
        1{ Get-LocalUser }
        2{
            #I modeled this after Microsoft's documentation, but adjusted to my needs.
            $userName = Read-Host "Please enter a username."
            $password = Read-Host -AsSecureString "Please enter a password"
            $params = @{
                Name = $userName
                Password = $password
            }
            New-LocalUser @params
        }
        3{
            $DisableUser = Read-Host "Please enter a user to delete."
            if (Get-LocalUser -Name $DisableUser -ErrorAction SilentlyContinue){
                Disable-LocalUser -Name $DisableUser
            }else{
                Write-Host "User does not exist."
            }
        }
        4{
            $stayLooping = $false
        }
        default{
            Write-Host "Invalid input, please select a number 1-4."
        }
        }
    }
}
function Clean-TempFiles{
    
}
function Test-NetworkConnection{
    $stayLooping = $true
    while($stayLooping){
        $choice = Read-Host "Select 1 to list all NICs and IPs, select 2 to ping an address, 3 to exit"
        switch($choice){
            1{ ipconfig /all }
            2{
                $unscsfl = $true
                $tries = 0
                $addr =Read-Host "Enter a Hostname or IP to ping"
                while($unscsfl -eq $true -and $tries -le 3){
                if (Test-Connection -TargetName $addr -Count 1 -Quiet){
                    Write-Host "Ping Success."
                    $unscsfl = $false
                }else{
                    Write-Host "Ping Failed."
                    $tries += 1
                }
            }
            }
            3{
                $stayLooping = $false
                return
            }
            default{
                Write-Host "Input not recognized, please try again."
            }
        }
    }

}
