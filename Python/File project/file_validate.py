import os
MAX_FILE_SIZE = 5 * 1024 * 1024
ALLOWED_EXTENSIONS = [".txt", ".pdf", ".jpg", ".png"]
def check_file_type(file_path, extension):
    try:
        with open(file_path, "rb") as file:
            header = file.read(8)
            if extension == ".pdf":
                return header.startswith(b"%PDF")
            elif extension == ".jpg":
                return header.startswith(b"\xff\xd8\xff")
            elif extension == ".png":
                return header.startswith(b"\x89PNG\r\n\x1a\n")
            elif extension == ".txt":
                try:
                    with open(file_path, "r" , encoding="utf-8") as file:
                        file.read()
                    return True
                except UnicodeDecodeError:
                    return False
    except OSError:
        return False
                

def file_validator(file_path):
    if not os.path.isfile(file_path):
        print("Error: File does not exist.")
        return False
    file_name = os.path.basename(file_path)
    extension = os.path.splitext(file_name)[1].lower()
    if extension not in ALLOWED_EXTENSIONS:
        print("File type invalid.")
        return False
    file_size = os.path.getsize(file_path)
    if file_size > MAX_FILE_SIZE:
        print("File is too big.")
        return False
    if not check_file_type(file_path,extension):
        print("Error: File contents do not match file type.")
        return False
    print("File validation passed")
    return True