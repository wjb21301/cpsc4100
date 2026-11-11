#!/bin/bash
#Here, I prompt the user to input a directory to backup.
echo "Enter a directory to backup"
#Here, we set the user inputted directory to be the variable sourceDir.
read sourceDir
echo "Create a log file."
read logFile
echo "Creating backup..."
#Now, I compress that directory, and save the tarball to a backup directory.
mkdir -p "$HOME/backup" && tar -czf "$HOME"/backup/backup_${sourceDir}_$(date +%Y%m%d).tar.gz $sourceDir
#Here, we just take contents of each of these commands, and write it to each text file.
df -h > /tmp/disk_usage.txt
uptime > /tmp/cpu_load.txt
free -m > /tmp/memory_usage.txt
#Finally, write everything to log file.
echo "Backup completed on $(date)" >> "$logFile"
cat /tmp/disk_usage.txt >> "$logFile"
cat /tmp/cpu_load.txt >> "$logFile"
cat /tmp/memory_usage.txt >> "$logFile"