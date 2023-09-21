func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func findMedianSortedArrays(X []int, Y []int) float64 {
    n,p:=len(X),len(Y)
    if n>p {
        X,Y=Y,X
        n,p=p,n
    }

    lo,hi:=0,n
    for lo<=hi {
        pX:=(lo+hi)/2
        pY:=(n+p+1)/2-pX

        hiX,loX:=math.MinInt64,math.MaxInt64
        hiY,loY:=math.MinInt64,math.MaxInt64

        if pX>0 {
            hiX=X[pX-1]
        }

        if pX<n {
            loX=X[pX]
        }

        if pY>0 {
            hiY=Y[pY-1]
        }

        if pY<p {
            loY=Y[pY]
        }

        if hiX<=loY && hiY<=loX {
            if (n+p)%2==0 {
                return (float64(max(hiX, hiY))+float64(min(loX,loY)))/2.0
            }
            return float64(max(hiX,hiY))
        } else if hiX>loY {
            hi=pX-1
        } else {
            lo=pX+1
        }

    }

    return 0.0
}