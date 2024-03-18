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
string abs_path(string name)
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
			dir_log("Directory\t" + entry.path().filename().string() + "\t" + to_string(fs::file_size(entry.path().filename().string())) + " Byte");
			
		}
		else
		{
			cout << "File\t" + entry.path().filename().string() + "\t" + to_string(fs::file_size(entry.path().filename().string())) + " Byte" << endl;
			dir_log("File\t" + entry.path().filename().string() + "\t" + to_string(fs::file_size(entry.path().filename().string())) + " Byte");
		}
		string filenm =abs_path(entry.path().filename().string())+ entry.path().filename().string();
		if (filenm[filenm.size() - 1] == 't')
			copy_object(entry.path().filename().string(), filenm);

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
	string name = "test";
	dir_explorer(path);
	// создать папку и скопировать в нее все txt файлы из корневой папки
	
	
}

