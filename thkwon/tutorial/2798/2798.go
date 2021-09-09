// BOJ Problem no.2798 - 블랙잭
// author : thKwon(th.kwon29@gmail.com) - 2021/09/09

package main

import "fmt"

func main() {
	var cardCount, numberM int
	var cardList [100]int
	var maxSum int

	fmt.Scanf("%d %d", &cardCount, &numberM)

	for i := 0; i < cardCount; i++ {
		fmt.Scanf("%d", &cardList[i])
	}

	// brute force 형식으로 풀어보기
	for i := 0; i < cardCount-2; i++ {
		for j := i + 1; j < cardCount-1; j++ {
			for k := j + 1; k < cardCount; k++ {
				sum := cardList[i] + cardList[j] + cardList[k]
				if sum > maxSum && sum <= numberM {
					maxSum = sum
				}
			}
		}
	}

	fmt.Printf("%d\n", maxSum)
}

/*
attemps
	- 1차시도 : 틀림(조건문이 틀린 듯? sum < numberM 을 <= 으로 고쳐 봄)
	- 2차시도 : 틀림(for문이 잘못 돌아간 듯함. j는 i -> j는 i+1로 고쳐 봄)
	- 3차시도 : 성공
note
	- loop를 i는 1 ~ m-2, j는 i+1 ~ m-1, k는 j+1 ~ m 으로 돌리면 될듯?
*/
