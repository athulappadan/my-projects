-- Huffman coding

import Data.Map
import Data.List
import Data.Function
import Data.Maybe

type FreqList   =   [(Char, Int)]

-- ^The frequency function calculates the number of occurances
frequency s     =   Data.Map.toList $ Prelude.foldl makeFreq Data.Map.empty s


-- | makeFreq is an auxillary function to create the frequency Map
makeFreq        ::  Map Char Int -> Char -> Map Char Int
makeFreq m c    =   Data.Map.insertWith (+) c 1 m


-- | HuffTree is the basic data structure used, contains Leaf and Branch 
data HuffTree   =   Branch {frq :: Int, lt :: HuffTree, rt :: HuffTree}
                    |   Leaf {symbol :: Char, frq :: Int}
                    deriving (Eq, Show)


instance Ord HuffTree where
        compare = compare `on` frq


-- | The mergeTree functions combines to HuffTrees by adding their frqs
mergeTree       ::  HuffTree -> HuffTree -> HuffTree
mergeTree x y   =   Branch (frq x + frq y) x y


-- | The makeTree function creates the final complete HuffTree
makeTree        ::  String -> HuffTree
makeTree        =   build . sort . Prelude.map (uncurry Leaf) . frequency
                    where
                        build       :: [HuffTree] -> HuffTree
                        build []    =  error "empty Leaf Tree"
                        build (t: []) = t
                        build (x:y:ts) = build $ Data.List.insert (mergeTree x y) ts


-- | encrypt accepts the HuffTree and returns corresponding code for individual chars
encrypt         ::  HuffTree -> [(Char, String)]
encrypt         =   encrypt' ""

encrypt'        ::  String -> HuffTree -> [(Char, String)]
encrypt' s (Leaf sym _)     =   [(sym, s)]
encrypt' s (Branch _ lt rt) =   encrypt' (s ++ "0") lt ++ encrypt' (s ++ "1") rt



type Code       =   String

-- | The encode functions returns the final encode string
encode          ::  String -> Code
encode s        =   encode' (encrypt $ makeTree s) s

encode'         ::  [(Char, String)] -> String -> Code
encode' _ []    =   []
encode' d (s:ss) =  (fromJust $ Prelude.lookup s d) ++ encode' d ss


-- | The decode function decodes the code
decode          ::  HuffTree -> Code -> String
decode t code   =   decode' t code
                    where
                        decode' (Branch _ lt rt) (c:cs) = 
                            case c of
                            '0' -> decode' lt cs
                            '1' -> decode' rt cs
                            _  ->  []
                        decode' (Leaf s _) cs = s : decode' t cs
                        decode' _ [] = []

