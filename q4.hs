data Results = AO | AR | SO | SR | F
instance Show Results where 
    show AO = "All Once"
    show AR = "All Repeat"
    show SO = "Some Once"
    show SR = "Some Repeat"
    show F = "False"

combine :: [Char]->String->Results
combine [] _ = F
combine a x | teste a x /= "" = F
            | teste2 a x == "" && teste2 x a == "" = AO
            | teste2 a x == "" && teste2 x a /= "" = AR
            | teste2 a x /= "" && teste2 x a == "" = SO
            | teste2 a x /= "" && teste2 x a /= "" = SR
            | otherwise = F

teste :: [Char]->String->[Char]
teste x [] = []
teste x (a:as) | bool' a x == True = teste x as
               | otherwise = (a):teste x as

bool' :: Char->[Char]->Bool
bool' y [] = False
bool' y (x:xs) | y == x = True
               | otherwise = bool' y xs

teste2 :: [Char]->String->[Char]
teste2 [] x = []
teste2 (x:xs) a | bool' x a == True = teste2 xs (tira x a)
                | otherwise = (x):teste2 xs (tira x a)

tira :: Char->String->[Char]
tira x []  = []
tira x (a:as) | x == a = as
              | otherwise = (a) : tira x as