// Design an in-memory file system to simulate the following functions:

// ls: Given a path in string format. If it is a file path, return a list that only contains this file's name.
// If it is a directory path, return the list of file and directory names in this directory.
// Your output (file and directory names together) should in lexicographic order.

// mkdir: Given a directory path that does not exist, you should make a new directory according to the path.
// If the middle directories in the path don't exist either, you should create them as well.
// This function has void return type.

// addContentToFile: Given a file path and file content in string format.
// If the file doesn't exist, you need to create that file containing given content.
// If the file already exists, you need to append given content to original content.
// This function has void return type.

// readContentFromFile: Given a file path, return its content in string format. 

// Example:

// Input: 
// ["FileSystem","ls","mkdir","addContentToFile","ls","readContentFromFile"]
// [[],["/"],["/a/b/c"],["/a/b/c/d","hello"],["/"],["/a/b/c/d"]]

// Output:
// [null,[],null,null,["a"],"hello"]

// Explanation:
// filesystem

// Note:
// * You can assume all file or directory paths are absolute paths which begin with / and do not end with / except that the path is just "/".
// * You can assume that all operations will be passed valid parameters and users will not attempt to retrieve file content or list a directory
//   or file that does not exist.
// * You can assume that all directory names and file names only contain lower-case letters, and same names won't exist in the same directory.

// https://leetcode.com/problems/design-in-memory-file-system/

class FileSystem {
    struct FileNode {
        map<string, FileNode*> dir;
        bool isFile;
        string content;
        
        FileNode(){
            isFile = false;
            content = "";
        }
    };
    
    FileNode* root;
    
    vector<string> getPathVec(const string& path)
    {
        vector<string> pahtVec;
        string word;
        istringstream ss(path);
        
        while (getline(ss, word, '/'))
        {
            if (word != "")
                pahtVec.push_back(word);
        }
        return pahtVec;         
    }
    
    FileNode* traverseAndCreateFilePath(const string& path)
    {
        vector<string> pathVec = getPathVec(path);
        
        FileNode* iter = root;
        
        for(string& s : pathVec)
        {
            if (!iter->dir.count(s))
                iter->dir[s] = new FileNode();
            
            iter = iter->dir[s];
        }
        
        return iter;
    }
public:
    FileSystem() {
        root = new FileNode;
    }
    
    vector<string> ls(string path) {
        vector<string> result;
        vector<string> pathVec = getPathVec(path);
        
        FileNode* iter = root;
        
        for(string& s : pathVec)
        {
            iter = iter->dir[s];
        }
        
        // If it is a file path, just return file name
        // Else return a list of all sub files/dir names
        if(iter->isFile)
        {
            result.push_back(pathVec.back());
        }
        else
        {
            for(auto& subFiles : iter->dir)
                result.push_back(subFiles.first);
        }
        
        return result;
    }
    
    void mkdir(string path) {
        traverseAndCreateFilePath(path);
    }
    
    void addContentToFile(string filePath, string content) {
        FileNode* iter = traverseAndCreateFilePath(filePath);
        iter->isFile = true;
        iter->content += content;
    }
    
    string readContentFromFile(string filePath) {
        FileNode* iter = traverseAndCreateFilePath(filePath);
        return iter->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */