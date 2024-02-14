module TD4 where

import Data.Char (isUpper)

-- Exercice 1.a
my_all :: (a -> Bool) -> [a] -> Bool
my_all p = not . (any (not . p))
--my_all p l = not (any (not . p) l)
-- Rem: not . p = \x -> not (p x)

-- Exercice 1.b
my_elem :: Eq a => a -> [a] -> Bool
my_elem e = any (== e)
--my_elem e l = any (== e) l

-- Exercice 2.a
uppers :: [Char] -> [Char] -- ou String -> String
uppers = filter isUpper -- import Data.Char
--uppers = filter (\c -> c >= 'A' && c <= 'Z')
--uppers = filter (elem ['A'..'Z'])

-- Exercice 2.b
includes :: Eq a => [a] -> [a] -> Bool
includes l1 = all (`elem` l1)
-- l1 `includes` l2 = all (\x -> x `elem` l1) l2

-- Exercice 3.a
data Document = Document { title :: String, keywords :: [String] }
-- ou : type Document = (String, [String])

-- Exercice 3.b.i
searchByKeyword :: String -> [Document] -> [Document]
searchByKeyword kw = filter (\doc -> kw `elem` (keywords doc))

-- Exercice 3.b.ii
searchByKeywords :: [String] -> [Document] -> [Document]
searchByKeywords kws = filter (\doc -> (keywords doc) `includes` kws)
--searchByKeywords kws = filter (\doc -> all (\w -> w `elem` (keywords doc))) kws

-- Exercice 3.c
relevance :: [String] -> Document -> Int
relevance kws doc = length $ filter (\kw -> kw `elem` (keywords doc)) kws
--relevance kws doc = foldl (\z kw -> if searchByKeyword kw doc then (z + 1) else z) 0 kws

-- Exercice 4.a
my_sum :: [Integer] -> Integer
my_sum = foldl (+) 0
--my_sum l = foldl (\z x -> z + x) 0 l

-- Exercice 4.b
my_max :: Ord a => [a] -> Maybe a
my_max      [] = Nothing
my_max (h : t) = Just (foldl max h t)
--my_max (h:t) = Just (foldl (\m e -> if e > m then e else m) h t)

-- Exercice 4.c

maxIndex :: Ord a => [a] -> Maybe Int
maxIndex [] = Nothing
maxIndex l@(h : t) = Just $ snd $ foldl op_maxIndex (h, 0) $ zip t [1..]
  where op_maxIndex (m, im) (x, i) = if m >= x then (m, im) else (x, i)


-- Exercice 5.a
data Pupil = Pupil { nom :: String, prenom :: String, notes :: [Double] } -- data Pupil = Pupil String String [Double]
data ReportCard = ReportCard { nomcpt :: String, moyenne :: Double }

-- Exercice 5.b
reports :: [Pupil] -> [ReportCard]
reports = map (\(Pupil n p ns) -> ReportCard (n ++ p) ((foldl (+) 0 ns) / (fromIntegral(length ns))))
--type Pupil = (string, string, [double])
--type ReportCard = (string, string, double)

-- Exercice 6.a
my_any :: (a -> Bool) -> [a] -> Bool
my_any p = foldl (\z x -> z || p x) False
--my_any p l = foldl (\z x -> z || p x) False l

my_find :: (a -> Bool) -> [a] -> Maybe a
my_find p = foldl (\z x -> if p x && isNothing z then Just x else z) Nothing -- import Data.Maybe
--my_find p = foldl op_find Nothing
--  where op_find Nothing x | p x = Just x
--        op_find z       _       = z

my_filter :: (a -> Bool) -> [a] -> [a]
my_filter p = foldl (\z x -> if p x then z ++ [x] else z) []
--my_filter p = foldr (\x z -> if p x then (x : z) else z) []

my_map :: (a -> b) -> [a] -> [b]
my_map f = foldl (\z x -> z ++ [f x]) []
--my_map f = foldr (\x z -> (f x) : z) []

-- Exercice 6.b.i
my_anyRec :: (a -> Bool) -> [a] -> Bool
my_anyRec _      [] = False
my_anyRec p (h : t) = p h || my_anyRec p t

my_findRec :: (a -> Bool) -> [a] -> Maybe a
my_findRec _      [] = Nothing
my_findRec p (h : t) = if p h then Just h else my_findRec p t

-- Exercice 6.b.ii
-- Recursif parce que fold doit parcourir toute la liste dans tous les cas

--- Exercice 6.c.i
my_partitionRec :: (a -> Bool) -> [a] -> ([a], [a])
my_partitionRec _      [] = ([], [])
my_partitionRec p (h : t) = if p h then (h : l1, l2) else (l1, h : l2)
  where (l1, l2) = my_partition p t

--- Exercice 6.c.ii
my_partition :: (a -> Bool) -> [a] -> ([a], [a])
my_partition p l = (filter p l, filter (not . p) l)
-- Recursif parce que elle ne parcourt la liste qu'une fois [1👍]

--- Exercice 7.a
prefixes :: [a] -> [[a]]
prefixes = foldl (\z x -> z ++ [last z ++ [x]]) [[]]
--prefixes l = foldr (\x z -> (init (head z)) : z) [l] l
--prefixes = foldr (\x z -> [] : (map (x :) z)) [[]]
--prefixes l = map (`take` l) [0..(length l)]