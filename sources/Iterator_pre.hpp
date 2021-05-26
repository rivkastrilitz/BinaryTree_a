#include "Node.hpp"
#include <stdio.h>

namespace ariel{

    template <typename treeType> class Iterator_pre {
        Node<treeType>* root;
        
        public:
            Iterator_pre(Node<treeType>* vertex):root(vertex){}

       
        // prefix increment 
        Iterator_pre<treeType>& operator++ ( ){
            return *this;
        }

        treeType& operator* (){
            return root->get_data();
        }

        bool operator != (Iterator_pre<treeType>& it){
            return false;
        }

       treeType * operator ->(){
            return &(operator*());
        }


    };
}