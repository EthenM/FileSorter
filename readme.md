# FileSorter
## v0.1.0

A console app to sort image/video files into folders by creation date.

> ***NOTE:*** The app currently will only sort the following files:
> - PNG*
> - JPG/JPEG
> - MOV*
> - MP4*
> - GIF*
>
> \*These file types don't have the proper metadata to be effectively sorted. instead, they are
> moved to an alternate "Unsortable" folder.

## Initial installation

- Take the contents of the FileSorter zip file, and move them into `%PROGRAM FILES%/EthenM/
  FileSorter` folder.
- Double click on the file titled: FileSorterAddRightClick.reg
    - This will add a new item to the right click menu on folders, allowing you to run the program
      from the right click menu.
- search and open the "Edit the system environment variables" app
    - click the "Environment Variables" button below the third box on the screen.
    - Under the system variables, find the "PATH" variable and click "Edit"
    - Add a new entry to this, being the path to the folder specified above (`%PROGRAM FILES%/
      EthenM/FileSorter`).
    - This will allow the computer to find the FileSorter program without needing to specify its
      path each time.
    - > ***NOTE:*** The computer may need to be restarted for this to take effect.
- The FileSorter App should be set up and ready to go

## Using the Application on the Command Line

- To use the app on the command line, enter into a new command line process and run the following:

        `FileSorter.exe <ROOT FOLDER>`

- The root folder is an optional parameter.
    - If it is not entered on the command line, it will be asked for later in the program.
- Follow execution of program as normal.

## Using the Application when Right-Clicking

- To use the right-click functionality, find the root folder desired in the file explorer.
- when the desired folder is found, right click.
    - right clicking on the background with nothing selected will run the program for the
      folder you are currently in.
    - right clicking on a folder while it is selected will run the program with that folder as the
      root.
- Click on the menu option "Sort Files"
    - If on windows 11, click the show more options button at the bottom of the menu that appears,
      if the program cannot be found.
- Follow the program execution as normal.

## Application Notes
- When selecting the sort type, the files will always be split into folders by years. Selecting the
  Months option will optionally store the files within `<SORTED FOLDER>/<YEAR>/<MONTH>/`.
- When selecting options from a menu, enter the ***NUMBER*** of the option wanted.
- It is advised to use the "Copy" transfer option. this will use more space on the drive, but allows
  you to double check that the program executed successfully, and that all files made it.
  Moving files always runs the risk of corruption, or an unintentional move, leading to unexpected
  results, and possibly the loss of files.
- The sorted directory will have the name `<ROOT FOLDER NAME>_sorted`, and will be stored either:
    - As a sibling to the root: if the root folder has a parent (e.g. it is not the C: drive),
      the sorted folder will be placed in the root folder's parent folder.
    - As a child to the root: if the root folder has no parent (e.g. it is the C: drive), the sorted
    folder will be placed as a child to the root folder.
