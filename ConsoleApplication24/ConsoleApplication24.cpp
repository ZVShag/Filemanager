#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

using namespace std;
namespace fs = filesystem;
void copy_object(string self, string other)
{
	try 
	{
		fs::copy(self, other);
	}
	catch (...)
	{
		cout << "Filed copy!";
	}
	
}
void temp_dir()
{
	fs::path tmp_dir = fs::temp_directory_path();

}
void abs_path(string name)
{
	cout<<fs::absolute(name).string();
}
string abs_pathr(string name)
{
	return fs::absolute(name).string();
}
bool object_exist(string name)
{
	if (fs::exists(name))
		return true;
	else
		return false;

}
void dir_log(string object)
{
	string fname="log.txt";
	ofstream fw(fname,ios_base::app);
	fw << object << endl;
	fw.close();

}
void dir_explorer(string path)
{
	fs::directory_iterator dr(path);
	for (const auto& entry : dr)
	{
		if (entry.is_directory())
		{
			cout << "Directory\t" + entry.path().filename().string()+"\t"+ to_string(fs::file_size(entry.path().filename().string()))+" Byte" << endl;
			//dir_log("Directory\t" + entry.path().filename().string() + "\t" + to_string(fs::file_size(entry.path().filename().string())) + " Byte");
			
		}
		else
		{
			cout << "File\t" + entry.path().filename().string() + "\t" + to_string(fs::file_size(entry.path().filename().string())) + " Byte" << endl;
			//dir_log("File\t" + entry.path().filename().string() + "\t" + to_string(fs::file_size(entry.path().filename().string())) + " Byte");
		}
		//string filenm =abs_path(entry.path().filename().string())+ entry.path().filename().string();
		//if (filenm[filenm.size() - 1] == 't')
			//copy_object(entry.path().filename().string(), filenm);

	}
}
void dir_create(string name)
{
	if (!object_exist(name))
	{
	if (fs::create_directories(name))
		cout << "Directory " + name + " was create!"<<endl;
	else
		cout << "Failed create directory!"<<endl;
	}
	else
		cout << "Encorrect name!" << endl;
}
void dir_delete(string name)
{
	if (object_exist(name))
	{
		if (fs::remove(name))
			cout << "Object " + name + " was delete!" << endl;
		else
			cout << "Failed delete object!" << endl;
	}
	else
		cout << "File not found!" << endl;
}

int main()
{
	
	string path = ".";
	while (true) {
		string dest = abs_pathr(path);
		cout << dest << endl;
		cout << "\nShow directory, input: s" << endl;
		cout << "Copy file, input: c" << endl;
		cout << "Goto, input: g" << endl;
		cout << "Delete file, input: d" << endl;
		cout << "Create file (directory), input: n" << endl;
		cout << "Abs_link file, input: a" << endl;
		string key;
		cin >> key;
		if (key == "c")
		{
			cout << "Copy file name:\n";
			string fl_name;
			string new_name;
			cin >> fl_name;
			cout << "Copy new_file name:\n";
			cin >> new_name;
			copy_object(fl_name, new_name);
		}
		if (key == "a")
		{
			cout << "File name:\n";
			string fl_name;
			cin >> fl_name;
			abs_path(fl_name);
		}
		if (key == "r")
		{

			string new_dir;
			cin >> new_dir;
			path = new_dir;
		}
	}


	
	
}

