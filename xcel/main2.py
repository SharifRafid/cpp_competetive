import camelot

tables = camelot.read_pdf("/home/sharifrafid/Downloads/Class Routine Spring 2025(Day) Final Version.pdf", pages='all', strip_text='\n', flavor='lattice')

all_data = []
for table in tables:
    df = table.df
    df = df.fillna("")
    records = df[1:].to_dict(orient="records")  # Skip header row manually if needed
    all_data.extend(records)

import json
with open("output.json", "w", encoding="utf-8") as f:
    json.dump(all_data, f, indent=2, ensure_ascii=False)
