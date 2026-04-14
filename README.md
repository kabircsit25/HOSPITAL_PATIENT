# Hospital Patient Management System

A C-based file handling project that lets you record and retrieve hospital patient data using text files. Written as part of a systems programming exercise covering structs, file I/O, and basic search functionality.

---

## Project Structure

```
HOSPITAL_PATIENT/
├── hosp_write.c       # Collects patient data and saves it to hospital.txt
├── hosp_read.c        # Reads and displays patient data, with city-based filtering
├── output/            # Compiled binaries (generated after build)
└── hospital.txt       # Data file (generated after running write program)
```

---

## What It Does

**hosp_write.c** — Data Entry  
Prompts the user to enter details for 24 patients one by one and saves them to `hospital.txt`. Each patient record stores:
- Name
- Age
- Address
- Medical condition
- Ward

**hosp_read.c** — Data Display and Search  
Reads `hospital.txt` and:
1. Displays all 24 patient records in a table
2. Asks the user to enter a city name and filters patients whose address contains that city

---

## Requirements

- GCC compiler (or any C99-compatible compiler)
- Terminal / Command Prompt
- Works on Windows, Linux, and macOS

---

## How to Compile

Open a terminal in the project folder and run:

**Write program:**
```bash
gcc hosp_write.c -o hosp_write
```

**Read program:**
```bash
gcc hosp_read.c -o hosp_read
```

---

## How to Run

**Step 1 — Enter patient data**

Run the write program first. It will ask you to enter details for 24 patients:

```bash
./hosp_write        # Linux / macOS
hosp_write.exe      # Windows
```

You will be prompted like this for each patient:

```
Patient 1:
Name: RamBahadur
Age: 45
Address (no spaces): Kathmandu
Condition (no spaces): Fever
Ward: General
```

> Note: Addresses and conditions cannot contain spaces. Use formats like `Kathmandu` or `ChestPain` (no gaps).

This saves all records to `hospital.txt` in the same folder.

**Step 2 — Read and search patient records**

```bash
./hosp_read         # Linux / macOS
hosp_read.exe       # Windows
```

This will first print all 24 patients, then ask:

```
Enter city to filter: Kathmandu
```

It will then display only the patients whose address contains that city name, along with a total count.

---

## Example Output

```
Details of 24 Patients:
Name         Age    Address       Condition     Ward
RamBahadur   45     Kathmandu     Fever         General
SitaDevi     32     Pokhara       Diabetes      ICU
...

Enter city to filter: Kathmandu

Patients from Kathmandu:
Name         Age    Address       Condition     Ward
RamBahadur   45     Kathmandu     Fever         General

Total patients from Kathmandu: 1
```

---

## Important Notes

- Always run `hosp_write` before `hosp_read`. The read program depends on `hospital.txt` existing.
- Both programs must be run from the same directory so they can find `hospital.txt`.
- The filter search is case-sensitive. Entering `kathmandu` will not match `Kathmandu`.
- The program expects exactly 24 patient records. Entering fewer will cause the read program to behave unexpectedly.

---

## Known Limitations

- Multi-word addresses (e.g. `New Baneshwor`) are not supported due to how `scanf` works. Use single-word addresses only.
- No option to update or delete existing records.
- Patient count is hardcoded to 24.

---

## Authors

- [@arunbohara20641213-hue](https://github.com/arunbohara20641213-hue)
- Forked from [@kabircsit25](https://github.com/kabircsit25/HOSPITAL_PATIENT)
