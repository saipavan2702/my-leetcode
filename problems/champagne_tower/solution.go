func champagneTower(poured int, qr int, qg int) float64 {
    
    pours := [101][101] float64{}
    pours[0][0] = float64(poured);
    
    for i := 0; i <= qr ; i++ {
      for j := 0 ; j <= i ; j++ {
        if pours[i][j] > 1 {
          pours[i+1][j] += (pours[i][j] - 1 )/ 2.0 ;
          pours[i+1][j+1] += (pours[i][j] - 1 )/ 2.0 ;
          pours[i][j] = 1.0;
        }
      }
    }
  return pours[qr][qg] ;
}

