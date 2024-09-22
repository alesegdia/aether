# Define the folder to monitor
$folderPath = "."

# Define the command to execute when a file is added or removed
$commandToExecute = {
    param ($event)
    Write-Host "File $($event.ChangeType): $($event.FullPath) at $(Get-Date)"
    # Example command: Add your command here
    Start-Process "genie.exe" -ArgumentList " --backend=backend-gl vs2022"
}

# Create a FileSystemWatcher
$watcher = New-Object System.IO.FileSystemWatcher
$watcher.Path = $folderPath
$watcher.IncludeSubdirectories = $true
$watcher.EnableRaisingEvents = $true

# Define the events to monitor
$watcher.Created += $commandToExecute
$watcher.Deleted += $commandToExecute

# Keep the script running
Write-Host "Monitoring changes in $folderPath. Press [Enter] to exit."
while ($true) {
    Start-Sleep -Seconds 1
    echo "meh"
}