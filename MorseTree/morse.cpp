#include "morse.hpp"

using namespace std;

MorseTree::MorseTree(istream & code_file)
{
    char ch;
    int n;
    int no_of_letters;
    string line;
    istringstream info;
    string letter;
    string code;
    
    
    
    code_file >> n;

    root = new TreeNode;
    TreeNode* ptr = root;
    while(code_file >> ch) {
        if(isalpha(ch)) {
            code_file >> line;
        }
        
        for(int i=0; i < line.size(); i++)
        {
            
            if(line[i] == '.')
            {
                if(ptr->lchild == nullptr)
                    ptr->lchild = new TreeNode;
                ptr = ptr->lchild;
            }
            else
            {
                if(ptr->rchild == nullptr)
                    ptr->rchild = new TreeNode;
                ptr = ptr->rchild;
            }
        }
        
        ptr->letter = ch;
        ptr = root;
    }
    
    
}


MorseTree::MorseTree(const MorseTree & original)
{
    TreeNode* Ptr = root;
    copy_tree(root, original.root);
}

MorseTree::~MorseTree()
{
    delete_tree(root);
}

MorseTree& MorseTree::operator=(const MorseTree & original)
{
    MorseTree copy(original);
    std::swap(copy.root, root);
    
    return *this;
    
    
}

void MorseTree::write(std::ostream & out)
{
    write_tree(out, root, 1);
}

void MorseTree::encode(std::istream & message_file, std::ostream & out)
{
    
    char ch;
    string code;
    string path;
    //Run a loop to get all the characters in.
    while(message_file.get(ch))
    {
        out << code << " ";
        //Use char to code to encode.
        if(isalpha(ch))
        {
            code = char_to_code(ch, root, path);
            out << code << " ";
        }
        
        if(ch == ' ')
        {
            out << "|";
        }
        
        if(ch == '\n')
        {
            out << "||";
        }
        
    }
}

void MorseTree::decode(std::istream& message_file, std::ostream& out)
{
    TreeNode* Ptr = root;
    char ch;
    char space;
    while(message_file >> ch)
    {
        if(ch == '.' && Ptr->lchild!=nullptr)
        {
            Ptr = Ptr->lchild;
            space = message_file.peek();
            if(space==' '){
                out << Ptr->letter;
                Ptr = root;
                //message_file.ignore();
            }
        }
        else if(ch == '-' && Ptr->rchild!=nullptr) //samplemessage.encoded
        {
            Ptr = Ptr->rchild;
            space = message_file.peek();
            if(space==' ') {
                out << Ptr->letter;
                Ptr = root;
                //message_file.ignore();
            }
        }
        else if(ch == '|')
        {
            //out << Ptr->letter;
            //Ptr = root;
            char next = message_file.peek();
            if(next == '|')
            {
                out << endl;
            }
                else
                {
                    out << ' ';
                }
            }
        }
        out << endl;
    }
    
