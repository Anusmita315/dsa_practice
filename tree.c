// 1.WACP to find no. of leaf node in the given binary tree.
Nleafnode (struct Btnode *P)
{
         if  (P = =  Null)
          return 0;
          else
          {
              if (P  lp == Null && P  rp == Null)
               return 1;
            else
              {
                 XL = Nleafnode (P lp)
                 XR = Nleafnode (P rp)
                 return (XL + XR)
               }
           }
}              
// 2.WACP to find no. of internal node in the given binary tree.
Internalnode (struct Btnode *P)
{
         if  (P = =  Null)
          return 0;
          else
          {
              if (P  lp == Null && P  rp == Null)
               return 0;
            else
              {
                 XL = Internalnode (P lp)
                 XR = Internalnode (P rp)
                 return (1+ XL + XR)
               }
           }
}              
// 3.WACP to find total no. of node in the given binary tree.
Totalnode (struct Btnode *P)
{
         if  (P = =  Null)
          return 0;
          else
          {
              if (P  lp == Null && P  rp == Null)
               return 1;
            else
              {
                 XL = Totalnode (P lp)
                 XR = Totalnode (P rp)
                 return (1+ XL + XR)
               }
           }
}              
// 4.WACP to find height of Binary tree.
Heightoftree (struct Btnode *P)
{
         if  (P = =  Null)
          return 0;
          else
          {
              if (P  lp == Null && P  rp == Null)
               return 0;
            else
              {
                 XL = Heightoftree (P lp)
                 XR = Heightoftree (P rp)
                 if (XL < XR )
                      return (XR  +1)
                 else return (XL +1)
               }
           }
}              
// 5.WACP to check given binary tree is strict binary tree or not.
StrictBT (struct Btnode *P)
{
         if  (P = =  Null)
          return (true);
          else
          {
              if (P  lp == Null && P  rp == Null)
               return (true);
            else
              {
                    if (P  lp! = Null && P  rp! = Null)
                   return (StrictBT (P  lp) && StrictBT (P  rp))
                    else
                          return (false);
               }
           }
}              
