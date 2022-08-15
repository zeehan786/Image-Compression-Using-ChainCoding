//main 
# include<fstream> 
# include <iostream> 
#include <string> 
#include "ChainCode.cpp" 
using namespace std;
int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments\n";
		std::cout << "argc = " << argc << std::endl;
		exit(0);
	}
	int numRows = 0, numCols = 0, minval = 0, maxval = 0;
	ifstream inFile, compressedtxt;
	inFile.open(argv[1]);
	if (inFile.fail()) cout << "Error in opening " << argv[1] << "\n";
	inFile >> numRows; inFile >> numCols; inFile >> minval; inFile >> maxval;
	std::string header = to_string(numRows) + " " + to_string(numCols) + " " + to_string(minval) + " " + to_string(maxval);
	std::string subname = "_chaincode.txt";
	std::string subname2 = "_boundary.txt";
	std::string subname3 = "_decompressed.txt";
	ofstream outFile(argv[1] + subname), outFile2(argv[1] + subname2), outFile3(argv[1] + subname3); ChainCode obj(numRows, numCols, minval, maxval, header);
	obj.loadImage(inFile);
	obj.GetChainCode(outFile); outFile.close(); compressedtxt.open(argv[1] + subname); obj.constBound(compressedtxt);
	obj.reformatPrettyPrint(outFile2, "Boundary:");
	obj.FillObject();
	//obj.showArray(obj.imgary, numRows, numCols); 
	obj.reformatPrettyPrint(outFile3, "Decompressed File:");
	inFile.close();
	outFile.close();
	outFile2.close();
	return 0;
}
