/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

type OptionalNode=TreeNode | null
type pI={
    first:number;
    second:number;
}

function averageOfSubtree(root: OptionalNode): number {

    let cnt:number=0;
    const recur=(node:OptionalNode):pI=>{
        if(!node) return {first:0,second:0};

        let l:pI=recur(node.left)
        let r:pI=recur(node.right)

        let S=(l.first+r.first+node.val);
        let C=(l.second+r.second+1);

        if(Math.floor(S/C)===node.val) cnt++
        return {first:S,second:C}
    }

    recur(root);
    return cnt;
};