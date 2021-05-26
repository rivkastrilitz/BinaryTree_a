#include "Node.hpp"
#include <stdio.h>

namespace ariel{
 template <typename treeType> class Iterator_post {
        Node<treeType>* root;
        public:
            Iterator_post(Node<treeType>* vertex):root(vertex){}

       
        // prefix increment 
        Iterator_post<treeType>& operator++ ( ){
            return *this;
        }

        treeType& operator* (){
            return root->get_data();
        }

        bool operator != (Iterator_post<treeType>& it){
            return false;
        }

        treeType* operator ->(){
            return &(operator*());
        }


    };

}