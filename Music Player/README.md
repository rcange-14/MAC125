# Music Player

**Author:** Ralph Cange  
**Language:** C++  
**IDE:** Visual Studio  
**Platform:** Windows only (uses Windows `Beep()` API)

---

## Description

A C++ console program that reads music notes from a text file and plays them through the computer's speaker using the Windows `Beep()` function. Each song is stored as a plain text file containing a list of frequencies (Hz) and durations (ms). The user types in the filename and the program loads and plays the song note by note.

---

## How It Works

1. The program prints a title screen
2. The user types the name of a song file (e.g. `MaryBeep.txt`)
3. The program opens the file and reads each pair of numbers — a frequency and a duration
4. Each note is played through the speaker using `Beep(frequency, duration)`
5. The frequency and duration are also printed to the console as each note plays

### Example Output
```
Music Player
--------------
Enter music File:
MaryBeep.txt
329 500
293 500
261 500
...
```

---

## Song Files Included

| File | Song |
|---|---|
| `MaryBeep.txt` | Mary Had a Little Lamb |
| `MIMUSIC.txt` | Mission Impossible Theme |

### How the Song Files Work

Each line has two numbers: `frequency duration`

```
329 500   ← play 329 Hz for 500 milliseconds
293 500   ← play 293 Hz for 500 milliseconds
261 500   ← play 261 Hz for 500 milliseconds
```

- **Frequency** is the pitch of the note in Hz (e.g. 261 = middle C)
- **Duration** is how long the note plays in milliseconds (500 = half a second)

---

## Code Breakdown

### `struct note`
A simple struct that holds one note — its frequency and duration.

```cpp
struct note {
    int freq;
    int duration;
};
```

---

### `title()`
Prints the program name and a divider line when the program starts.

```cpp
void title() {
    cout << "Music Player\n";
    cout << "--------------\n";
}
```

---

### `input()`
Asks the user to type a filename and returns it as a string.

```cpp
string input() {
    cout << "Enter music File: " << endl;
    string songname;
    cin >> songname;
    return songname;
}
```

---

### `LoadSong()`
Opens the file and reads every frequency/duration pair into two vectors — `f` for frequencies and `d` for durations.

```cpp
void LoadSong(vector<note>& S, ifstream& fileinput) {
    int freq, duration;
    do {
        fileinput >> freq >> duration;
        // stores each value into the global vectors f and d
    } while (!fileinput.eof());
    fileinput.close();
}
```

---

### `player()`
Loops through the frequency and duration vectors and plays each note using `Beep()`, which is a built-in Windows function.

```cpp
void player(const vector<note>& Music) {
    for (int i = 0; i < f.size(); ++i) {
        cout << f[i] << " " << d[i] << endl;
        Beep(f[i], d[i]);
    }
}
```

---

## Files

| File | Description |
|---|---|
| `MusicPlayer.cpp` | Main source code |
| `MaryBeep.txt` | Song file — Mary Had a Little Lamb |
| `MIMUSIC.txt` | Song file — Mission Impossible Theme |
| `MusicPlayerCode.txt` | Earlier version of the player with a hardcoded song menu |

---

## Concepts Used

- Structs
- Vectors (`std::vector`)
- File I/O (`ifstream`)
- Functions with parameters and return values
- Windows API (`Beep()`)
- Do-while loops
- Global variables

---

## How to Run

1. Open the project in **Visual Studio**
2. Make sure the song `.txt` files are in the **same folder** as the compiled `.exe`
3. Press `Ctrl + F5` to build and run
4. Type one of the song filenames when prompted:
   - `MaryBeep.txt`
   - `MIMUSIC.txt`

> **Note:** `Beep()` only works on Windows. The program will not compile or play audio on Mac or Linux.

---

## Adding Your Own Songs

You can create your own song file by making a `.txt` file with one note per line in this format:

```
frequency duration
frequency duration
```

Look up the Hz value for any musical note online, then convert your desired note lengths to milliseconds (e.g. 500ms = half a second). Save the file in the same folder as the program and type its name when prompted.
