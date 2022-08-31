/* 
* https://leetcode.com/problems/zigzag-conversion/
*/
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
	if(numRows == 1) {
		return s;
	}
	let result = Array.from('-'.repeat(s.length));
	let indexes = Array.from({length: s.length}, (v,k) => 0);
	let sizes = Array.from({length: s.length}, (v,k) => 0);
	for(let i=0; i<numRows; i++) {
		sizes.push(0);
		indexes.push(0);
	}
	let isPillar = true;
	for(let i=0, j=0; i<s.length; i++) {
		sizes[j]++;
		if(isPillar) {
			if(j<(numRows-1)) {
				j++;
			} else {
				isPillar = false;
				j--;
			}
		} else {
			if(j>0) {
				j--;
			} else {
				isPillar=true;
				j++;
			}
		}
	}
	for(let i=0, k=0; i<indexes.length; i++) {
		indexes[i] = k;
		k += sizes[i];
	}
	for(let i=0, j=0; i<s.length; i++) {
		let c = s.charAt(i);
		result[indexes[j]++] = c;
		if(isPillar) {
			if(j<(numRows-1)) {
				j++;
			} else {
				isPillar = false;
				j--;
			}
		} else {
			if(j>0) {
				j--;
			} else {
				isPillar=true;
				j++;
			}
		}
	}
	return result.join('');
};

console.log(convert("ABCDEFGHI", 4));


