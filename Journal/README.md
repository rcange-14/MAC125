# Journal = Message Object + Storage Manager

**Author:** Ralph Cange  
**Language:** C++  
**IDE:** Visual Studio

---

## Description

A C++ program that simulates a simple phone message journal. You can add messages to a journal, save them to a text file, and reload them later. It demonstrates the use of structs, file input/output, vectors, and operator overloading.

---

## How It Works

The program runs two functions back to back:

1. **main1()** – Creates a new journal, adds messages to it, prints them, then saves to a file
2. **main2()** – Loads the saved journal from the file and prints the messages back out

### Example Output
```
these me my messages:
DailyPhoneMessages
10am from AMGEN
11:30 am lunch
5:00pm Mac125

journal saved

my old messages :
DailyPhoneMessages
10am from AMGEN
11:30 am lunch
5:00pm Mac125
```

---

## Code Breakdown

### `struct Message`
Holds the journal data — a title and a list of message entries.

```cpp
struct Message {
    string title;
    vector<string> entries;

    Message(const string& title = " ") : title(title) { }
    void add(const string& entry);
};
```

- `title` — the name of the journal
- `entries` — a vector (list) that stores each message as a string
- `add()` — adds a new message to the entries list using `push_back()`
- The `::` in `void Message::add(...)` is the **scope resolution operator** — it connects the function definition back to the struct it belongs to

---

### `struct FileManager`
Handles saving and loading the journal to/from a file. Both functions are `static`, meaning you can call them without creating a FileManager object.

```cpp
struct FileManager {
    static void save(const Message& j, const string& filename);
    static void load(Message& j, const string& filename);
};
```

- **save()** — opens a file using `ofstream` and writes the title and each entry line by line
- **load()** — opens a file using `ifstream`, reads the first line as the title, then reads each remaining line as a message entry

---

### `operator<<` Overload
Allows the journal to be printed directly with `cout`.

```cpp
ostream& operator<<(ostream& out, const Message& j) {
    out << j.title << endl;
    for (const auto m : j.entries)
        out << m << endl;
    return out;
}
```

Without this, you would have to print the title and each entry manually every time. With it, you can just write `cout << journal`.

---

## Files

| File | Description |
|---|---|
| `Journal = Message Object + Storage Manager.cpp` | Main source file with all the code |
| `Journal = Message Object + Storage Manager.vcxproj` | Visual Studio project file |
| `Journal = Message Object + Storage Manager.vcxproj.filters` | Visual Studio filter/folder config |
| `Office text` | Output file generated when the program runs (created automatically) |

---

## Concepts Used

- Structs
- Vectors (`std::vector`)
- File I/O (`ofstream`, `ifstream`)
- Scope resolution operator (`::`)
- Operator overloading (`<<`)
- Static member functions
- Range-based for loops

---

## How to Run

1. Open the `.vcxproj` file in **Visual Studio**
2. Press `Ctrl + F5` to build and run without debugging
3. The program will print messages to the console and save them to a file called `Office text` in the project directory
