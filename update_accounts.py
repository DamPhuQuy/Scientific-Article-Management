import json
import random
import string
import os

def generate_key(length=6):
    return ''.join(random.choices(string.ascii_letters + string.digits, k=length))

file_path = 'data/accounts.json'

if not os.path.exists(file_path):
    print(f"Error: {file_path} not found.")
    exit(1)

with open(file_path, 'r') as f:
    data = json.load(f)

updated_count = 0
for user in data:
    if 'keyManipulation' not in user:
        user['keyManipulation'] = generate_key()
        updated_count += 1

with open(file_path, 'w') as f:
    json.dump(data, f, indent=4)

print(f"Successfully updated {updated_count} users with keyManipulation.")
