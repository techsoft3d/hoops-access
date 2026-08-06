#include <stdio.h>
#include "sam/base/base.h"
#include "sam/base/license.h"
#include "sam/hoops_license.h"

static void
print_id(Vobject* obj)
{
    Vint* val;

    val = (Vint*)obj;
    printf("parent= %d, value= %d\n", val[1], val[0]);
}

static void
print_tree(vsy_Tree* tree, Vint node)
{
    Vobject* obj;
    Vint child;

    vsy_TreeGetValue(tree, node, &obj);
    print_id(obj);

    vsy_TreeFirstChild(tree, node, &child);
    while (child != 0) {
        print_tree(tree, child);
        vsy_TreeNextChild(tree, child, &child);
    }
}

/*----------------------------------------------------------------------
                      Test and demonstrate Tree
----------------------------------------------------------------------*/
int
main()
{
    vsy_Tree* tree;
    Vint root, c[3], child, g2_1, g2_2;
    Vint value[1000][2];

    vsy_LicenseValidate(HOOPS_LICENSE);

    /* instance object */
    tree = vsy_TreeBegin();

    /* extract root node */
    vsy_TreeAddNode(tree, 0, &root);
    value[root][0] = root;
    value[root][1] = 0;
    vsy_TreeSetValue(tree, root, (Vobject*)&value[root]);

    /* add 3 children to root */
    vsy_TreeAddNode(tree, root, &c[0]);
    value[c[0]][0] = c[0];
    value[c[0]][1] = root;
    vsy_TreeSetValue(tree, c[0], (Vobject*)&value[c[0]]);

    vsy_TreeAddNode(tree, root, &c[1]);
    value[c[1]][0] = c[1];
    value[c[1]][1] = root;
    vsy_TreeSetValue(tree, c[1], (Vobject*)&value[c[1]]);

    vsy_TreeAddNode(tree, root, &c[2]);
    value[c[2]][0] = c[2];
    value[c[2]][1] = root;
    vsy_TreeSetValue(tree, c[2], (Vobject*)&value[c[2]]);

    /* add a child to c[2] */
    vsy_TreeAddNode(tree, c[2], &child);
    value[child][0] = child;
    value[child][1] = c[2];
    vsy_TreeSetValue(tree, child, (Vobject*)&value[child]);

    /* add 2 grandchildren to c[2] */
    vsy_TreeAddNode(tree, child, &g2_1);
    value[g2_1][0] = g2_1;
    value[g2_1][1] = child;
    vsy_TreeSetValue(tree, g2_1, (Vobject*)&value[g2_1]);

    vsy_TreeAddNode(tree, child, &g2_2);
    value[g2_2][0] = g2_2;
    value[g2_2][1] = child;
    vsy_TreeSetValue(tree, g2_2, (Vobject*)&value[g2_2]);

    /* list all children recursively */
    printf("Tree after all insertions:\n");
    vsy_TreeForEach(tree, print_id);

    /* remove one node */
    vsy_TreeDelNode(tree, child);

    /* list all children recursively */
    printf("\nTree after removing node %d:\n", child);
    print_tree(tree, root);

    /* re-insert a child to c[2] */
    vsy_TreeAddNode(tree, c[2], &child);
    value[child][0] = child;
    value[child][1] = c[2];
    vsy_TreeSetValue(tree, child, (Vobject*)&value[child]);

    /* re-insert 2 grandchildren to c[2] */
    vsy_TreeAddNode(tree, child, &g2_1);
    value[g2_1][0] = g2_1;
    value[g2_1][1] = child;
    vsy_TreeSetValue(tree, g2_1, (Vobject*)&value[g2_1]);

    vsy_TreeAddNode(tree, child, &g2_2);
    value[g2_2][0] = g2_2;
    value[g2_2][1] = child;
    vsy_TreeSetValue(tree, g2_2, (Vobject*)&value[g2_2]);

    printf("\nTree after reinsertion of children:\n");
    vsy_TreeForEach(tree, print_id);

    vsy_TreeEnd(tree);
    return 0;
}
