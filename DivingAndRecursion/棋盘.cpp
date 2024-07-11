// void chessBoard(int tr, int tc, int dr, int dc, int size)
// {
//     if (size==1) 
//     	return;
//     int s = size/2;      
//     int t = ++num;      
    
    
//     if (dr < tr + s && dc < tc +s)                
//     {
       
//         chessBoard(tr,tc,dr,dc,s);
//     }
//     else             
//     {
         
//         Matrix[tr+s-1][tc+s-1] = t;
         
//         chessBoard(tr,tc,tr+s-1,tc+s-1,s);
//     }
    
    
//     if (dr < tr + s && dc >= tc + s )           
//     {
         
//         chessBoard(tr,tc+s,dr,dc,s);
//     }
//     else             
//     {
       
//         Matrix[tr+s-1][tc+s] = t;
         
//         chessBoard(tr,tc+s,tr+s-1,tc+s,s);
//     }
    
      
//     if (dr >= tr + s && dc < tc + s)
//     {
       
//         chessBoard(tr+s,tc,dr,dc,s);
//     }
//     else
//     { 
//         Matrix[tr+s][tc+s-1] = t;
        
//         chessBoard(tr+s,tc,tr+s,tc+s-1,s);
//     }
    
      
//     if (dr >= tr + s && dc >= tc + s)
//     {
          
//         chessBoard(tr+s,tc+s,dr,dc,s);
//     }
//     else
//     {
         
//         Matrix[tr+s][tc+s] = t;
        
//         chessBoard(tr+s,tc+s,tr+s,tc+s,s);
//     }
// }