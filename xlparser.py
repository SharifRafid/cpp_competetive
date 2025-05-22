import pandas as pd

# Load the Excel file
df = pd.read_excel("/home/sharifrafid/Downloads/Class Routine Spring 2025(Day) Final Version.xlsx", sheet_name=0, dtype=str)

# Fill NaN with empty string to keep empty fields
df = df.fillna("")

# Convert to JSON
json_data = df.to_dict(orient="records")

# Save to file
import json
with open("output.json", "w", encoding="utf-8") as f:
    json.dump(json_data, f, indent=2, ensure_ascii=False)
