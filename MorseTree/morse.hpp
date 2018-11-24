#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

class MorseTree
{
private:
    struct TreeNode {
        char letter;
        TreeNode* lchild;
        TreeNode* rchild;
        
        TreeNode(char alphabet='*', TreeNode* dot=nullptr, TreeNode* dash=nullptr)
        : letter(alphabet), lchild(dot), rchild(dash) {}
    };
    
    TreeNode* root;
    TreeNode* copy_tree(TreeNode* source_root, TreeNode* copy_root)
    {
        
        TreeNode* Ptr = source_root;
        // Ptr = source_root;
        if(Ptr == nullptr)
        {
            Ptr = new TreeNode('*', nullptr, nullptr);
        }
        else
        {
            if(Ptr->lchild!=nullptr)
            {
                copy_tree(Ptr, Ptr->lchild);
            }
            else if(Ptr->rchild!=nullptr)
            {
                copy_tree(Ptr, Ptr->rchild);
            }
            copy_root = new TreeNode(Ptr->letter, Ptr->lchild, Ptr->rchild);
        }
        
        return copy_root;
    }
    
void delete_tree(TreeNode* source_root){
        TreeNode* Ptr = source_root;
        if(Ptr!=NULL)
        {
            if(Ptr->lchild!= NULL)
            {
                delete_tree(Ptr->lchild);
            }
            if(Ptr->rchild != NULL)
            {
                delete_tree(Ptr->rchild);
            }
            delete Ptr;
        }
        
    }
    
void write_tree(std::ostream& out,  TreeNode* local_root, const int depth)
    {
        TreeNode* Ptr = local_root;
        if(Ptr == nullptr)
        {
            return;
        }
        // Step 1 - right child
        write_tree(out, Ptr->rchild, depth+1);
        
        // Step 2 - Process Node
        out <<  std::setw(depth * 8) << Ptr->letter << std::endl;
        
        // Step 3 - Go left
        write_tree(out, Ptr->lchild, depth+1);
    }
    
std::string char_to_code(char ch, const TreeNode* t, std::string path_so_far)
    {
        
        std::string code;
        if(t->lchild!=nullptr)
        {
            //path_so_far += ".";
            char_to_code(ch, t->lchild, path_so_far+".");
        }
        if(t->rchild!=nullptr)
        {
            path_so_far += "-";
            char_to_code(ch, t->rchild, path_so_far);
        }
        if(t->letter != ch)
        {
            path_so_far = "";
        }
        code = path_so_far;
        
        if(code!= "")
            return code;
    
    return ".-.";
}
    
    
public:
    MorseTree(std::istream & code_file);
    MorseTree(const MorseTree & original);
    ~MorseTree();
    MorseTree& operator=(const MorseTree & original);
    void write(std::ostream & out);
    void encode(std::istream & message_file, std::ostream & out);
    void decode(std::istream& message_file, std::ostream& out);
    
};
