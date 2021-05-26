#pragma once
#include <iterator>
#include <iostream>
#include <stdio.h>
#include "Node.hpp"
#include "Iterator_in .hpp"
#include "Iterator_post.hpp"
#include "Iterator_pre.hpp"

using namespace std;
namespace ariel{

    template <typename T> class BinaryTree{
        Node<T>* root;

        

        public:
        BinaryTree(){
            root=nullptr;
        }
        ~BinaryTree(){}

        BinaryTree& add_root(T data){
            // if(this->root==nullptr){
            //     root=new Node<T>(data);

            // }else{
            //     root->set_data(data);
            // }

            return *this;

        }
        
        Node<T>& get_root(){
            return this->root;
        }

        BinaryTree& add_left(T ex_node,T node_data){
            // if(find_node(ex_node,this->root)==NULL){
            //     throw("cant add left to unexisted node");
            // }
            // Node<T>* n =new Node<T>(node_data);
            // find_node(ex_node,this->root).set_left(n);
            return *this;
        }


        BinaryTree& add_right(T ex_node,T node_data){
            // if(find_node(ex_node,this->root)==NULL){
            //     throw("cant add right to unexisted node");
            // }
            // Node<T>* n =new Node<T>(node_data);
            // find_node(ex_node,this->root).set_right(n);
            return *this;
        }

        Iterator_pre<T>& begin_preorder(){
            Iterator_pre <T>& it =*(new Iterator_pre <T>(this->root));
            return it;
        }

        Iterator_pre<T>& end_preorder(){
            Iterator_pre <T>& it =*(new Iterator_pre <T>(nullptr));
            return it;
            
        }

    
        Iterator_in<T>& begin_inorder(){
            Iterator_in <T>& it =*(new Iterator_in <T>(this->root));
            return it;
            
        }

        Iterator_in<T>& end_inorder(){
            Iterator_in <T>& it =*(new Iterator_in <T>(nullptr));
            return it;
          
        }

        Iterator_post<T>& begin_postorder(){
            Iterator_post <T>& it =*(new Iterator_post <T>(this->root));
            return it;
            
        }

        Iterator_post<T>& end_postorder(){
            Iterator_post <T>& it =*(new Iterator_post <T>(nullptr));
            return it;
            

        }

        Iterator_in<T>& begin(){
            return begin_inorder();
        }
        Iterator_in<T>& end(){
            return end_inorder() ;
        }




        friend ostream& operator<<(ostream& out,const BinaryTree<T>& tree){
            return out;
        }
        
        Node<T>& find_node (T n ,Node<T>* root){
            if(root==NULL){
                return NULL;
            }

            if(root->get_data()==n){
                return root;
            }

            find_node(n,root->get_left());
            find_node(n,root->get_right());

        }

        // Node<T>& find_end_pre(Node<T>* root){
        //     if(root==NULL){
        //         return NULL;
        //     }

        //     if(root.get_right()!=NULL){
        //         find_end_pre(root->get_right());
        //     }else{
        //         if(root.get_left()!=NULL){
        //         find_end_pre(root->get_left());
        //         }else{
        //             return root;
        //         }
        //     }
        // }

        Node<T>& find_begin_post(Node<T>* root){
            if(root==nullptr){
                return NULL;
            }

            if(root->get_left()!=NULL){
                find_begin_post(root->get_left());
            }else{
                if(root->get_right()!=NULL){
                find_begin_post(root->get_right());
                }else{
                    return root;
                }
            }
        }

        Node<T>& find_begin_in(Node<T>* root){
            if(root==NULL){
                return NULL;
            }

            if(root->get_left()!=NULL){
                find_begin_in(root->get_left());
            }else{
                return root;
            }
           
        }

        // Node<T>& find_end_in(Node<T>* root){
        //     if(root==NULL){
        //         return NULL;
        //     }

        //     if(root.get_right()!=NULL){
        //         find_end_in(root->get_left());
        //     }else{
        //         return root;
        //     }
           
        // }

        



    };




   
}
