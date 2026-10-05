import os, shutil
from file_validate import file_validator
from malware_scan import scan_file

UPLOAD_FOLDER = "./uploads"

def upload_file():
    print("\n--------- Upload File ----------")
    file_path = input("Enter file path")
    if not os.path.isfile(file_path):
        print("Error, file does not exist.")
        return
    print(f"File Selected: {os.path.basename}")
    if not file_validator(file_path):
        print("File rejected.")
        return
    if not scan_file(file_path):
        print("Malware Detected, or scan failed.")
        return
    file_name = os.path.basename(file_path)
    destination = os.path.join(UPLOAD_FOLDER, file_name)
    shutil.copy2(file_path, destination)
    print("File Uploaded.")

def view_uploaded_files():
    print("\n--------- Uploaded Files ----------")
    os.makedirs(UPLOAD_FOLDER, exist_ok=True)
    files = os.listdir(UPLOAD_FOLDER)
    if not files:
        print("No files found.")
        return
    for file in files:
        print(file)

def main():
    os.makedirs(UPLOAD_FOLDER, exist_ok=True)
    
    while True:
        print("\n------Secure File Upload System--------")
        print("1. Upload a file. Only .jpg, .pdf, .png, or .txt allowed.")
        print("2. View your files")
        print("3. Exit")
        
        choice = input("Please choose an option.")
        
        if choice == "1":
            upload_file()
        elif choice == "2":
            view_uploaded_files()
        elif choice == "3":
            print("Exiting Program.")
            break
        else:
            print("Invalid input, please try again.")

if __name__ == "__main__":
    main()
            
    