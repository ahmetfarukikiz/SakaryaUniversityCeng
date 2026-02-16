/**
* @file BstNode.cpp
* @description bst ağacının düğümü
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 4.12.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/

#include "BstNode.hpp"

BstNode::BstNode(int value){
    data = value;
    left = NULL;
    right = NULL;
}