function findSingle(nums) {
    let result = 0;
    for (const num of nums) {
        result ^= num;
        }
    return result;
}

const nums = [1, 1, 2, 2, 3, 3, 4, 4, 5];
const single = findSingle(nums);
console.log("single element:", single);
