$stayLooping = $true
while ($stayLooping) {
    Write-Host "====Networking common commands utility===="
    Write-Host "1 - netstat"
    Write-Host "2 - ipconfig"
    Write-Host "3 - arp -a"
    Write-Host "4 - nslookup"
    Write-Host "5 - ping"
    Write-Host "6 - clear"
    Write-Host "7 - exit script"
    $userInput = Read-Host -Prompt "Please make a selection"
    switch ($userInput) {
        1 {
            Write-Host "=====NETSTAT===="
            Write-Host "1 - Show all connections/listeners (-a)"
            Write-Host "2 - Show all numerical adresses (-n)"
            Write-Host "3 - Show PIDs (-o)"
            Write-Host "4 - Show all + numerical + PID (-ano)"
            Write-Host "5 - Return to main menu"
            $netstatInput = Read-Host -Prompt "Please make a selection for your netstat arguments."
            switch ($netstatInput) {
                1 { netstat -a }
                2 { netstat -n }
                3 { netstat -o }
                4 { netstat -ano }
                5 {}
                default {
                    Write-Host "Invalid selection, please enter a number 1-5."
                }
            }
        }
        2 {
            Write-Host "=====IPCONFIG====="

            Write-Host "1 - Show basic IP configuration"
            Write-Host "2 - Show detailed configuration (/all)"
            Write-Host "3 - Show DNS cache (/displaydns)"
            Write-Host "4 - Flush DNS cache (/flushdns)"
            Write-Host "5 - Release DHCP address (/release) WARNING: THIS COMMAND WILL DISCONNECT FROM NETWORK, USE WITH CAUTION."
            Write-Host "6 - Renew DHCP address (/renew) "
            Write-Host "7 - Return to main menu"

            $ipconfigInput = Read-Host -Prompt "Please make a selection for ipconfig"

            switch ($ipconfigInput) {
                1 { ipconfig }
                2 { ipconfig /all }
                3 { ipconfig /displaydns }
                4 { ipconfig /flushdns }
                5 { ipconfig /release }
                6 { ipconfig /renew }
                7 { }

                default {
                    Write-Host "Invalid selection. Please enter a number between 1-7."
                }
            }


        }
        3 { 
            Write-Host "=====ARP====="

            Write-Host "1 - Show ARP table (-a)"
            Write-Host "2 - Show ARP table with numerical addresses (-n)"
            Write-Host "3 - Show ARP entry for a specific IP (-a IP)"
            Write-Host "4 - Delete an ARP entry (-d IP)"
            Write-Host "5 - Return to main menu"

            $arpInput = Read-Host -Prompt "Please make a selection for ARP"

            switch ($arpInput) {
                1 { arp -a }

                2 { arp -a -n }

                3 {
                    $arpIP = Read-Host "Enter an IP address"
                    arp -a $arpIP
                }

                4 {
                    $arpIP = Read-Host "Enter the IP address to delete"
                    arp -d $arpIP
                }

                5 { }

                default {
                    Write-Host "Invalid selection. Please enter a number between 1-5."
                }
            } 
        }
        4 {
            $nslookupInput = Read-Host -Prompt "Please enter an ip or hostname to use with nslookup"
            nslookup $nslookupInput
        }
        5 {
            $pingInput = Read-Host -Prompt "Please enter an ip or hostname to use with ping."
            ping $pingInput
        }
        6 { clear }
        7 { $stayLooping = $false }
        default {
            Write-Host "Invalid selection, please enter a number between 1-5"
        }
    }
}