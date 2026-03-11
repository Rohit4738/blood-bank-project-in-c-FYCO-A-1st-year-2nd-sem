# 🩸 Blood Bank Management System (C)

<p align="center">

![Language](https://img.shields.io/badge/Language-C-blue)
![Level](https://img.shields.io/badge/Level-Beginner-green)
![Project](https://img.shields.io/badge/Project-College-orange)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

</p>

<p align="center">
A simple <b>console-based Blood Bank program written in C</b> that stores donor information using file handling.
</p>

---

# ✨ Features

* 🧾 Add donor details
* 🩺 Check donor eligibility (Age ≥ 18)
* 💾 Save donor data to a file
* 📋 View all stored donors
* 🖥️ Simple menu-driven interface

---

# 📸 Program Menu

```text
--- Blood Bank Menu ---

1. Add Donor
2. View Donors
3. Exit
```

---

# ⚙️ How The Program Works

The program runs inside an **infinite loop** using:

```c
while(1)
```

This continuously shows the menu until the user selects **Exit**.

---

## 1️⃣ Add Donor

The program asks the user to enter:

* Name
* Age
* Blood Group

Example input:

```text
Enter Name: Rahul
Enter Age: 20
Enter Blood Group: O+
```

Then the program checks:

```c
if(age >= 18)
```

If the donor is **18 or older**, they are eligible to donate blood.

The data is then saved to:

```
bloodbank.txt
```

Example stored data:

```text
Rahul 20 O+
Priya 22 A+
Aman 19 B+
```

---

## 2️⃣ View Donors

The program reads data from **bloodbank.txt** and displays it like this:

```text
Name: Rahul | Age: 20 | Blood Group: O+
Name: Priya | Age: 22 | Blood Group: A+
```

---

## 3️⃣ Exit

Stops the program using:

```c
break;
```

---

# 📂 Project Structure

```
blood-bank-project-in-c-FYCO-A-1st-year-2nd-sem
│
├── bloodbank.c
├── bloodbank.txt
└── README.md
```

---

# 🧠 C Concepts Used

| Concept       | Purpose                  |
| ------------- | ------------------------ |
| Variables     | Store donor data         |
| Arrays        | Store text like names    |
| Loops         | Menu system              |
| Conditions    | Check donor eligibility  |
| File Handling | Save and read donor data |

---

# 📚 Important C Commands Explained

## `printf()`

Prints output to the console.

```c
printf("Hello World");
```

---

## `scanf()`

Reads input from the user.

```c
scanf("%d", &age);
```

---

## `FILE *fp`

Creates a **file pointer** used for file operations.

---

## `fopen()`

Opens a file.

```c
fp = fopen("bloodbank.txt", "a");
```

File modes:

| Mode | Meaning                   |
| ---- | ------------------------- |
| `r`  | Read file                 |
| `w`  | Write / overwrite         |
| `a`  | Append (add data to file) |

---

## `fprintf()`

Writes formatted data to a file.

```c
fprintf(fp,"%s %d %s\n", name, age, blood);
```

---

## `fscanf()`

Reads formatted data from a file.

```c
fscanf(fp,"%s %d %s", name, &age, blood);
```

---

# 🚀 Compile & Run

### Compile

```bash
gcc bloodbank.c -o bloodbank
```

### Run

```bash
./bloodbank
```

---

# 🎯 Learning Goals

This project was made to practice:

* Basic **C Programming**
* **Loops**
* **Conditional statements**
* **File handling**
* **Menu-driven programs**

---
