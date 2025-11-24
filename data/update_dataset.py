import json
import random
import os

# File path
file_path = 'dataset.json'

# Predefined locations
locations = [
    "New York, USA", "London, UK", "Tokyo, Japan", "Paris, France",
    "Berlin, Germany", "Sydney, Australia", "Toronto, Canada",
    "Singapore", "Beijing, China", "Mumbai, India"
]

def update_dataset():
    if not os.path.exists(file_path):
        print(f"Error: {file_path} not found.")
        return

    with open(file_path, 'r', encoding='utf-8') as f:
        data = json.load(f)

    updated_count = 0
    for entry in data:
        # Update hIndex
        if 'hIndex' in entry and (entry['hIndex'] == 0 or entry['hIndex'] is None):
            entry['hIndex'] = random.randint(1, 50)
            updated_count += 1

        # Update sjr
        if 'sjr' in entry and (entry['sjr'] == 0.0 or entry['sjr'] is None):
            entry['sjr'] = round(random.uniform(0.1, 2.0), 2)
            updated_count += 1

        # Update impact_factor
        if 'impact_factor' in entry and (entry['impact_factor'] == 0.0 or entry['impact_factor'] is None):
            entry['impact_factor'] = round(random.uniform(0.5, 10.0), 2)
            updated_count += 1

        # Update q_rank
        if 'q_rank' in entry and (entry['q_rank'] == 0 or entry['q_rank'] is None):
            entry['q_rank'] = random.randint(1, 4)
            updated_count += 1

        # Update acceptance_rate
        if 'acceptance_rate' in entry and (entry['acceptance_rate'] == 0.0 or entry['acceptance_rate'] is None):
            entry['acceptance_rate'] = round(random.uniform(10.0, 40.0), 1)
            updated_count += 1

        # Update location
        if 'location' in entry and (entry['location'] == "" or entry['location'] is None):
            entry['location'] = random.choice(locations)
            updated_count += 1

    with open(file_path, 'w', encoding='utf-8') as f:
        json.dump(data, f, indent=2, ensure_ascii=False)

    print(f"Successfully updated {updated_count} fields in {len(data)} entries.")

if __name__ == "__main__":
    update_dataset()
