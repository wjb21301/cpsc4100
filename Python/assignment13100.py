def validateEmail(email):
    return '@' in email and '.' in email
def sanitizeInput(message):
    return message.replace('&','')
email = input("Please enter an email.")
message = input("Please enter a message")
checkedEmail = validateEmail(email)
sanitizedInput = sanitizeInput(message)
print(f"Original email: ", email)
print(f"Original message: ", message)
print(f"Is email valid? ", checkedEmail)
print(f"Sanitized input ", sanitizedInput)
