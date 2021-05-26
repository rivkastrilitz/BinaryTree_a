#include "Node.hpp"
#include <stdio.h>

namespace ariel{


    template <typename treeType> class Iterator_in {
        Node<treeType>* root;
        public:
            Iterator_in(Node<treeType>* vertex):root(vertex){}
        
        // prefix increment 
        Iterator_in<treeType>& operator++ ( ){
            return *this;
        }

        treeType& operator* (){
            return root->get_data();
        }

        bool operator != (Iterator_in<treeType>& it){
            return false;
        }

        treeType * operator ->(){
            return &(operator*());
        }

    };




}