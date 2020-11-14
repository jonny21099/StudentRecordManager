# StudentRecordManager
A C++ management software for teachers that records information about students and keeps track of their payments. This program uses QT for all GUI components. 

## Features
1. Personalized and unique user accounts

2. Local SQLITE database

3. User-friendly GUI

4. TableView for clear data visualization

5. Calendar widget to keep track of schedules

## Instructions
1. Register an account.

![Screenshot from 2020-11-13 22-05-28](https://user-images.githubusercontent.com/43177180/99140187-9fec9380-25fc-11eb-9e88-be74aca28985.png)

2. Enter requested information and make sure all constraints are met.

![Screenshot from 2020-11-13 22-07-46](https://user-images.githubusercontent.com/43177180/99140193-ac70ec00-25fc-11eb-86b0-719a76d86a65.png)

3. Once all constraints are satisfied, and the account is made, a success message will display.

![Screenshot from 2020-11-13 22-08-19](https://user-images.githubusercontent.com/43177180/99140201-c01c5280-25fc-11eb-85c9-a2d4ce88fc49.png)

4. You can now login with your newly created account and access all the features.

![Screenshot from 2020-11-13 22-09-33](https://user-images.githubusercontent.com/43177180/99140242-3a4cd700-25fd-11eb-91fd-31399f2cd891.png)

5. Users have access to 5 options.

![Screenshot from 2020-11-13 22-16-56](https://user-images.githubusercontent.com/43177180/99140309-f4dcd980-25fd-11eb-9fd9-70a047a2a05d.png)

## Creating an executable program
1. Download the repository.

2. Open the repository in QtCreator.

3. Change the directory to where you want to create the executable.

![Screenshot from 2020-11-13 22-25-04](https://user-images.githubusercontent.com/43177180/99140465-8a2c9d80-25ff-11eb-99d7-0b63ccfdac30.png)

The following steps differ between windows and linux.

### Linux
4. Open terminal and cd to the directory.

5. ``` ./RecordManager.pro ```

### Windows
4. Go to the folder where the project was built.

5. Copy the RecordManager application and the accounts.db file into a new folder.

![image](https://user-images.githubusercontent.com/43177180/99141351-e398ca80-2607-11eb-998b-48c705964657.png)

6. Open MinGW.

![image](https://user-images.githubusercontent.com/43177180/99141369-04612000-2608-11eb-856b-6bbcc4173987.png)

7. cd to the folder where the project was built and windeployqt RecordManager.exe.

```
cd "C:\Users\admin\builtDirectory"
windeployqt RecordManager.exe
```
8. Run RecordManager.exe.

## Contributions

For more information about QT checkout their program and plans [here](qt.io)

[More information](doc.qt.io) on the QT documentation.
