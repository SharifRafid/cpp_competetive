import pdfplumber
import json

all_data = []

with pdfplumber.open("/home/sharifrafid/Downloads/Class Routine Spring 2025(Day) Final Version.pdf") as pdf:
    for page in pdf.pages:
        tables = page.extract_tables()
        for table in tables:
            headers = table[0]
            for row in table[1:]:
                row += [""] * (len(headers) - len(row))
                data = dict(zip(headers, row))
                all_data.append(data)

with open("output.json", "w", encoding="utf-8") as f:
    json.dump(all_data, f, indent=2, ensure_ascii=False)
