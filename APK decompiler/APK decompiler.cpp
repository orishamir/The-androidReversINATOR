#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

void disassembleAPK(string apkName) {
	system("cls");
	int apkOrDex;
	cout << "\n\n\n                Would you rather:\n\n";
	cout << "                1. Use apktool.jar to disassemble " << apkName << " to a folder.\n";
	cout << "                2. Use dex2jar.bat to convert " << apkName << " into .jar.\n";
	cout << "            >>> ";
	cin >> apkOrDex;
	if (apkOrDex == 1) {
		printf("\n\n\n                Please make sure that \"apktool.jar\" and the APK file is in the same folder as this program.\n\n");
		cout << "                Using APKTOOL to decompile " << apkName << "...\n\n";
		system(("apktool.jar d -f -r " + apkName).c_str());
		char useDex2jar;
		// apk Name.substr(0, apkFileName.size() - 4) is apk file name without the .apk, substr start at 0, gets only up until every letter minus 4, which is .APK
		if (apkName[0] == '"' && apkName[apkName.size() - 1] == '"')
			cout << "                I have decompiled your APK. you should see a folder named " << '"' << apkName.substr(1, apkName.size() - 6) << "\"\n\n";
		else
			cout << "                I have decompiled your APK. you should see a folder named " << '"' << apkName.substr(0, apkName.size() - 4) << "\"\n\n";
		cout << "                Now, would you like me to convert your APK to A jar for easier reading? (Y/n): ";

		cin >> useDex2jar;
		//--------------------------------
		if (useDex2jar == 'y' || useDex2jar == 'Y') {
			cout << "\n\n                OK. make sure \"dex2jar-2.0\" folder is in the same folder.\n\n";
			system(("dex2jar-2.0\\d2j-dex2jar.bat " + apkName).c_str());
			if (apkName[0] == '"' && apkName[apkName.size() - 1] == '"')
				cout << "\n\n                You should now see a file named:\"" << apkName.substr(1, apkName.size() - 6) << "-dex2jar.jar\"\n\n\n";
			else
				cout << "\n\n                You should now see a file named:\"" << apkName.substr(0, apkName.size() - 4) << "-dex2jar.jar\"\n\n\n";
		}	

	}
	else if (apkOrDex == 2) {
		// dex2jar first. to decompile----------------------
		cout << "\n\n\n                Using dex2jar to convert \"" << apkName << "\" to .jar...\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // 4 = red
		cout << "\n\n                Make sure \"dex2jar-2.0\" folder is in the same folder.\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 7 = default
		system("pause & echo. & echo.");
		system(("dex2jar-2.0\\d2j-dex2jar.bat " + apkName).c_str());
		if (apkName[0] == '"' && apkName[apkName.size() - 1] == '"')
			cout << "\n\n                You should now see a file named:\"" << apkName.substr(1, apkName.size() - 6) << "-dex2jar.jar\"\n\n\n";
		else
			cout << "\n\n                You should now see a file named:\"" << apkName.substr(0, apkName.size() - 4) << "-dex2jar.jar\"\n\n\n";
		cout << "                Now, would you like me to use Apktool to convert your apk file into a folder? (Y/n): ";
		char useApktooljar;
		cin >> useApktooljar;
		if (useApktooljar == 'y' || useApktooljar == 'Y') {
			// apk Name.substr(0, apkFileName.size() - 4) is apk file name without the .apk, substr start at 0, gets only up until every letter minus 4, which is .APK
			system(("apktool.jar d -f -r " + apkName).c_str());
			if (apkName[0] == '"' && apkName[apkName.size() - 1] == '"')
				cout << "                I have decompiled your APK. you should see a folder named " << '"' << apkName.substr(1, apkName.size() - 6) << "\"\n\n";
			else
				cout << "                I have decompiled your APK. you should see a folder named " << '"' << apkName.substr(0, apkName.size() - 4) << "\"\n\n";
		}
		
		//--------------------------------
		printf("                Great. now that I finished, I will exit the program.\n\n");
		system("pause");		
	}	
}

void reassembleAPK(string folderName, string folderNameNoQ) {
	int option;
	system("cls");
	cout << "\n\n\n\n                First, you must need to understand:\n";
	cout << "                1. You NEED apktool.jar to build the APK file from the folder.\n";
	cout << "                2. You NEED keytool.jar to create a keystore to sign the APK with.\n";
	cout << "                3. You NEED jarsigner.jar to sign the APK (doesn't work yet).\n\n";
	cout << "                Choose an option.\n";
	cout << "            >>> ";
	cin >> option;
	if (option == 1) {
		cout << "\n\n\n                If you are here, this means you want to convert your folder into an APK file.\n";
		cout << "                I will now use APKTOOL to do so.\n\n";
		system(("apktool.jar b " + folderName).c_str());
		cout << "\n                Now. you will see in \"" << folderNameNoQ << "\\dist\" a file named \"" << folderNameNoQ << ".apk\"\n";
		cout << "                Wait. you don't see it? perhaps your program's code isn't correct.\n";
		cout << "                I will now redirect you, so you will be able to sign your apk file.\n\n\n";
		system("pause");
		reassembleAPK(folderName,folderNameNoQ);
	}
	else if (option == 2) {
		string keytoolLocation;

		cout << "\n\n\n                If you are here, this means you want to create a keystore.\n";
		cout << "                For this, there are things you need to do.\n";
		cout << "                1. You need to choose a password.\n";
//		cout << "                2. Please bring your generated APK"
		cout << "                2. You need to locate keytool.jar. (default location is:\"C:\\Program Files\\Java\\jdk-VERSION\bin\")\n\n";
		cout << "                Please enter the location of your keytool.jar file. (include \" and .exe)\n";
		cin.ignore();
		getline(cin, keytoolLocation);
		cout << "                I will now run the command: \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // 11 = bright cyan
		cout << keytoolLocation << " -genkey -keystore " << folderNameNoQ << ".keystore -validity 1000 -alias " << folderNameNoQ << "\n\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 7 = default
		system((keytoolLocation + " -genkey -keystore " + folderNameNoQ + ".keystore -validity 1000 -alias " + folderNameNoQ).c_str());
		cout << "                You should now see a file named \"" << folderNameNoQ << ".keystore\"\n\n";
		cout << "                I will now redirect you to the previous menu.\n\n\n";
		system("pause");
		reassembleAPK(folderName,folderNameNoQ);
	}
	else if (option == 3) {

	}
	
}

int main()
{
	system("cls");
	system("title Ori's APK decompile tool");

	int action = 0;
	string apkFileName;
	string folderName;
	printf("\n\n\n");
	
	
	printf("                Thanks for using my tool.\n");
	printf("                Choose your action:\n\n");
	printf("                1. Decompile & disassemble APK file\n");
	printf("                2. Recompile a folder into an APK file\n            >>> ");
	cin >> action;
	if (action == 1) {
		//printf("                Please make sure that \"apktool.jar\" and the APK file is in the same folder as this program.\n\n");
		printf("\n\n\n                Please enter the .APK file name: ");
		cin.ignore();
		getline(cin ,apkFileName);
		// check if the name contains '"', if so, check if user already entered .APK, if not, remove the '"', then add .APK, then add '"'.
		// user did not enter " in front.
		if (apkFileName[apkFileName.size() - 1] != '"' && apkFileName[0] != '"')
			apkFileName = "\"" + apkFileName + "\"";
		
		if (apkFileName[0] == '"' && apkFileName[apkFileName.size() - 1] == '"') {
			if (apkFileName.size() < 5 || !(apkFileName[apkFileName.size() - 5] == '.')) {				
				apkFileName = apkFileName.substr(0, apkFileName.size() - 1);				
				apkFileName += ".apk\"";		
			}
		}
		else {
			if (apkFileName.size() < 5 || !(apkFileName[apkFileName.size() - 4] == '.'))
				apkFileName += ".apk";
		}		
		disassembleAPK(apkFileName);
	}
	else if (action == 2) {
		//reassemble app
		
		printf("\n\n\n                Please enter the folder name: ");
		cin.ignore();
		getline(cin, folderName);
		string folderNameNoQ = folderName;
		if (folderName[folderName.size() - 1] != '"' || folderName[0] != '"')			
				folderName = "\"" + folderName + "\"";
		reassembleAPK(folderName, folderNameNoQ);
	}
	else {
		printf("\n\n                        please enter a valid option.\n\n\n");
		system("pause");
		
	}
}
