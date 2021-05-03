# Unscrambler
A C++ program that creates all possible options of a given word and checks if it is present in the file `words.txt`. In `words.txt` are currently 450k english words stored.

## Installation
1. Download the [latest binary release](https://github.com/MaFeLP/Unscrambler/release/latest) for your platform:
        - `Unscrambler.exe` for Windows-64bit systems
        - `Unscrambler-Linux` for Linux-64bit systems
        - `Unscrambler-Mac` for Intel based Mac systems.
2. Download the `words.txt` file from [latest releases](https://github.com/MaFeLP/Unscrambler/release/latest) and put it into the same folder, as the binary from step 1.
3. Follow the next steps, only if you use windows!
        1. Press and hold the `windows`-key, next to your `Ctrl`-key.
        2. Press the letter `R` on your keyboard.
        3. Release both keys.
        3. Empty the box, that popped up in the bottom left corner of your screen.
        4. If it is empty, type `regedit` and then press `OK`.
        5. If asked a user control prompt, click `Yes`.
        6. In the Registry window, you should see a bar on the left ahnd side, like the one in your explorer. In there, navigate to the folder `Computer\HKEY_CURRENT_USER\Console`.
        7. On the right hand side of the window, you should now see many values, having in it `ColorTable00`, `ColorTable01`, etc.
        8. In the empty white space on the right/middle of this window, make a right click and select `New -> DOWRD (32-bit)`.
        9. If prompted for the name, type `VirtualTerminalLevel` and press `OK.
        10. Then Double click the newly created value (should be highlighted blue).
        11. A new window should have popped up, asking you for the value.
        12. Set the value to `1` and click `OK`.
        13. You can now close this window.

## Executing the program
### Windows
1. Make sure you have the `words.txt` file in the same folder, as `Unscrambler.exe`.
2. Double click the `Unscrambler.exe` file.
3. See [usage](#Usage) for the usage of the program.
4. If the program has outputted all the words,  and said, that it exited, you can continue with Step 5.
5. To close the program, either close the window or type any character and press enter.

### MacOS/Linux
1. Open a terminal.
2. Change the directory with `cd ` to the directory, in which the Binary is located. (You can list all avaliable directories with `ls`).
3. If you are in the directory with the binary and the words.txt file, type `./Unscrambler-Mac` to execute the program.
4. Continue with Usage.

## Usage
1. Execute the program.
2. Type the letters you want to unscramble and then press enter.
3. Type in the number of threads, you want to use and then press enter.
4. Wait for the progress bar to fill and/or the program to say, that it has exited.

## Building from source
⚠️⚠️ Only continue from here, if you know, what you are doing ⚠️⚠️ <br><br>
1. Get the source files by either using git or getting the files, by downloading the zip Archive and extracting it.
```bash
git clone https://github.com/MaFeLP/Unscrambler.git
cd Unscrambler/
```

2. You **can** use the predefined makefile, but it would be better if you would make your own, using cmake.<br>
You can create a makefile, by using the command:
```bash
cmake CMakeLists.txt
```

3. Build the binary with the following command:
```bash
make
```
