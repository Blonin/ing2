--module a importer
{-
import Data.Char (isAlphaNum)
import Data.List (groupBy, length)
import Data.Map (Map,fromList)

-- Function to count symbol occurrences
symbolCount :: String -> Map Char Int
symbolCount message =
  let groups = groupBy (\c1 c2 -> isAlphaNum c1 == isAlphaNum c2) message
  in fromList $ map (\group -> (head group, length group)) groups
-}

import Data.Char (ord)
import Data.List (groupBy, length)
import Data.Map (fromList,Map)

-- Function to count symbol occurrences
symbolCount :: String -> Map Char Int
symbolCount message =
  let charCounts = map (\c -> (c, length (filter (== c) message))) (supp message)
  in fromList charCounts

supp :: Ord a => [a] -> [a]
supp = foldr (\x xs -> if x `elem` xs then xs else x : xs) []



-- Example usage (assuming main is defined elsewhere)
main = do
  let message = "je comprend pas"
  let counts = symbolCount message
  print counts

{- 
    ghci pour lancer le prompt de haskell
    :l nomDufichier.hs Permet de charcger le fichier
    :r pour rechercher les fichier charger
-}
{-
main :: IO ()
main = putStrLn "Hello, Haskell!"


--Int -2^63 2^63
maxInt = maxBound ::Int 

-- Integer unbound num 
-- Float
-- Double
bigFloat = 3.99999
-- Bool True False
-- Char ''
-- Tuple
always5 :: Int
always5 = 5

--permet de faire la somme des chiffre de 1 à 1000
sumOfNums= sum[1..1000]

--prefixe
modExPre = mod 5 4
--Infixe
modExIn = 5 `mod` 4


negNumEX = 5 + (-4)
-- :t sqrt nous affiche le manuel haskell de sqrt

num9 = 9 :: Int
--fromIntegral permet de changer le "changer" le type de la valeur
sqrtOf9 = sqrt (fromIntegral num9)

--list
primeNum = [3.5.7.11]
morePrimes = primeNum ++ [13,17,19,23,29]

favNums = 2: 7 : 21 : 66 :[]

multList = [[3,5,7],[11,13,17]]

--Ne fonctionne pas :/
--morePrimes2 = 2:morePrimes 

zeroToTen = [0..10]

evenList = [2,4..20]

letterList = ['A','C'..'Z']

infinPow10 = [10,20..] --liste infini mais n'affiche que jusqu'au chiffre que l'on a besoin

many2s = take 10 (repeat 2)

many3s= replicate 10 3

cycleList = take 13 (cycle[1,2,3,4,5])

listTimes3 = [x*3 | x <-[1..10], x*3 <=50]

divideBy9N13 = [x | x<- [1..500], x `mod` 13 == 0, x `mod`9 == 0]

sortedList = sort [9,1,5,7,62,31,56,8]

sumOfLists = zipWith
-}
