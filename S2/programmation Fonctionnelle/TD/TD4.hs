module TD4 where

import Data.Char (isUpper)
import Data.Maybe (isNothing)
import Data.List (sort, sortOn, unfoldr)

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
my_max (h : t) = Just $ foldl max h t

-- Exercice 4.c
maxIndex :: Ord a => [a] -> Maybe Int
maxIndex      [] = Nothing
  maxIndex (h : t) = Just $ snd $ foldl op_maxIndex (h, 0) $ zip t [1..]
    where op_maxIndex (m, im) (x, i) = if m >= x then (m, im) else (x, i)

{-
-- Exercice 5.a
data Pupil = Pupil { nom :: String, prenom :: String, notes :: [Double] } -- data Pupil = Pupil String String [Double]
data ReportCard = ReportCard { nomcpt :: String, moyenne :: Double }
--type Pupil = (string, string, [double])
--type ReportCard = (string, string, double)

-- Exercice 5.b
reports :: [Pupil] -> [ReportCard]
reports = map (\(Pupil n p ns) -> ReportCard (n ++ p) ((foldl (+) 0 ns) / (fromIntegral(length ns))))
-}

-- Exercice 6.a
my_any :: (a -> Bool) -> [a] -> Bool
my_any p = foldl (\z x -> z || p x) False
--my_any p l = foldl (\z x -> z || p x) False l

my_find :: (a -> Bool) -> [a] -> Maybe a
my_find p = foldl (\z x -> if p x && isNothing z then Just x else z) Nothing
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
my_partition p l = (filter p l, filter (not . p) l)
-- Recursif parce que elle ne parcourt la liste qu'une fois [1👍]

--- Exercice 7.a
prefixes :: [a] -> [[a]]
--prefixes = foldl (\z x -> z ++ [(last z) ++ [x]]) [[]]
--prefixes l = foldr (\x z -> (init (head z)) : z) [l] l
--prefixes = foldr (\x z -> [] : (map (x :) z)) [[]]
prefixes l = map (`take` l) [0..(length l)]

--- Exerice 7.b
join :: [a] -> [b] -> [(a, b)]
--join l1 l2 = foldl (\z x -> foldl (\z1 y -> z1 ++ [(x, y)]) z l2) [] l1
--join l = foldl (\z x -> z ++ map (\y -> (y, x)) l) []
--join l1 l2 = concatMap (\x -> map (\y -> (x,y)) l2) l1
join l1 l2 = [(x, y) | x <- l1, y <- l2]

--- Exercice 8.a
data User = User { nom :: String, prenom :: String, age :: Integer }
  deriving (Eq, Ord)
data Student = Student { stuUser :: User, year :: Integer }
  deriving (Eq, Ord)
data Teacher = Teacher { tchrUser :: User, dep :: String, seniority :: Integer }
  deriving (Eq, Ord)

--- Exercice 8.b.i
yearList :: [Student] -> Integer -> [Student]
yearList sts y = sort [st | st <- sts, (year st) == y]
--yearList sts y = sort (filter (\st -> (year st) == y) l)

--- Exercice 8.b.ii
deptList :: [Teacher] -> String -> [Teacher]
deptList ts d = sort [t | t <- ts, (dep t) == d]
--deptList ts d = sort (filter (\t -> (dep t) == d) ts)

--- Exercice 8.b.iii
partOfFurniture :: [Teacher] -> [Teacher]
partOfFurniture ts = sort [t | t <- ts, seniority t >= 10]
--partOfFurniture ts = sort (filter (\t -> (seniority t) >= 10) ts)

--- Exercice 8.b.iv
studentsOlderThanTeachers :: [Student] -> [Teacher] -> [(Student, Teacher)]
studentsOlderThanTeachers sts ts = [(st, t) | st <- sts, t <- ts, (age (stuUser st)) >= (age (tchrUser t))]

--- Exercice 8.c.i
data Room = Room { rName :: String, rBat :: String, capacity :: Integer } deriving (Eq, Ord)
data Course = Course { teacher :: Teacher, cYear :: Integer, room :: Room, start :: Integer, duration :: Integer } deriving (Eq, Ord)

--- Exercice 8.c.ii
schedule :: [Course] -> Teacher -> [Course]
schedule cs t = sortOn start [c | c <- cs, (teacher c) == t]
--schedule cs t = sortOn start (filter (\c -> (teacher c) == t) cs)

timetable :: [Course] -> Student -> [Course]
timetable cs st = sortOn start [c | c <- cs, (cYear c) == year st]
--timetable cs t = sortOn start (filter (\c (cYear c) == year st) cs)

overbooked :: [Student] -> [Course] -> [Course]
overbooked sts cs = [c | c <- cs, (capacity (room c)) < (toInteger (length (yearList sts (cYear c))))]
--overbooked sts = filter (\c -> (capacity (room c)) < (toInteger (length (yearList sts (cYear c))))

conflicts :: [Course] -> [(Course, Course)]
conflicts cs = [(c1, c2) | c1 <- cs, c2 <- cs, (c1 < c2) && c1 `conflictsWith` c2]

conflictsWith :: Course -> Course -> Bool
c1 `conflictsWith` c2 = ((c1 /= c2)) && (start c1 == start c2) && ((teacher c1 == teacher c2) || (cYear c1 == cYear c2) || (room c1 == room c2))

--- Exercice 9.a
fixed :: (a -> a) -> a -> Int -> a
--fixed next initial times = head $ drop times $ iterate next initial -- <=> head (drop times (iterate next initial))
--fixed next initial times = last (take times (iterate next initial))
fixed next initial times = iterate next initial !! times

whilst :: (a -> a) -> a -> (a -> Bool) -> a
--whilst next initial cont = fromJust (find (not . cont) (iterate next initial))
whilst next initial cont = head $ dropWhile cont $ iterate next initial
-- head sur un dropwhile
-- first !cont ?

recurrence :: (Integer -> a -> a) -> a -> [a]
recurrence f u0 = map snd $ iterate (\(n, u) -> (n + 1, f n u)) (0, u0)
recurrence f u0 = unfoldr (\(n, u) -> Just (u, (n + 1,f n u))) (0, u0) -- import Data.List




--iterate :: forall a. (a -> a) -> a -> [a]
--Defined in ‘GHC.List’ (base-4.18.1.0)

--iterate f x returns an infinite list of repeated applications of f to x :

--iterate f x == [x, f x, f (f x), ...]
--Note that iterate is lazy, potentially leading to thunk build-up if the consumer doesn't force each iterate. See iterate' for a strict variant of this function.

-- >>> take 10 $ iterate not True
--[True,False,True,False...

-- >>> take 10 $ iterate (+3) 42
--[42,45,48,51,54,57,60,63...






