#pragma once

namespace ariel{
    template <typename T>
    class Node{
        private:
            Node<T>* left=nullptr;
            Node<T>* right=nullptr;
            Node<T>* father=nullptr;
            T data;
            


        public:
            Node(T d){
                this->data=d;
            }

            void set_data(T d){
                this->data=d;
            }

            T& get_data(){
                return this->data;
            }

            void set_left(Node<T>* n){
                this->left=n;
            }

            Node* get_left(){
                return this->left;
            }

            void set_right(Node<T>* n){
                this->right=n;
            }

            Node* get_right(){
                return this->right;
            }
            
            Node* get_father(){
                return this->father;
            }

            void set_father(Node<T>* n){
                this->father=n;
            }


    };
}