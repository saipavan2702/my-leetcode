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

function findMode(root: TreeNode | null): number[] {
    const store:number[]=[]

    const inorder=(node: TreeNode | null):void=>{
        if(!node) return;
        inorder(node.left)
        store.push(node.val)
        inorder(node.right)
    }
    inorder(root)
    const count={}
    let ans=0

    store.map((data:number)=>{
        if(count[data]){
            count[data]++;
        }else{
            count[data]=1;
        }

        ans=Math.max(ans,count[data]);
    })

    const final:number[]=[]
    for(let x in count){
        if(count[x]==ans) final.push(parseInt(x));
    }
    return final;

};