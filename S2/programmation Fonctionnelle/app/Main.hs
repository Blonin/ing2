--module a importer
import Data.List
import System.IO

{- 
    ghci pour lancer le prompt de haskell
    :l nomDufichier.hs Permet de charcger le fichier
    :r pour rechercher les fichier charger
-}

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
modEx = mod 5 4
--Infixe
modEx = 5 'mod' 4


negNumEX = 5 + (-4)
-- :t sqrt nous affiche le manuel haskell de sqrt

num9 = 9 :: Int
sqrtOf9 = sqrt (fromIntegral num9)