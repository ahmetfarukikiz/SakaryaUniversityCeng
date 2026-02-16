#include "BST.hpp"
#include "Avl.hpp"

int main(){
    Avl<int> *avl = new Avl<int>();
    Bst<int> *bst = new Bst<int>();
    int sayilar[] = {12, 30, 7, 41, 36, 3, 83, 70, 18};
    for(int i=0; i<9;i++){
        avl->add(sayilar[i]);
        bst->add(sayilar[i]);
    }
    cout << "Yukseklik: " << avl->height() << endl;
    if(bst->search(41)) cout << "41 bulundu" << endl;
    else cout << "41 bulunamadi" << endl;

    cout << "inorder: " << endl;
    bst->inorder();
    cout << endl;

    cout << "preorder: " << endl;
    bst->preorder();
    cout << endl;

    cout << "postorder(bst): " << endl;
    bst->preorder();
    cout << endl;

    cout << "postorder(avl): " << endl;
    avl->postorder();
    cout << endl;

    cout << "levelorder: " << endl;
    bst->levelOrder();
    cout << endl;
}