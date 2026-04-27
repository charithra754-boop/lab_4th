"""
question 4: market basket analysis using apriori algorithm.
this script implements the apriori algorithm from scratch to find frequent itemsets
and generate association rules from a list of transactions.
"""

from itertools import combinations

def get_frequent_itemsets(transactions, min_support):
    # step 1: count frequency of individual items
    item_counts = {}
    for transaction in transactions:
        for item in transaction:
            if item in item_counts:
                item_counts[item] += 1
            else:
                item_counts[item] = 1
                
    # keep only items that meet minimum support
    total_transactions = len(transactions)
    frequent_1_itemsets = {frozenset([item]): count / total_transactions
                           for item, count in item_counts.items()
                           if count / total_transactions >= min_support}
    
    # iterate to find larger frequent itemsets
    all_frequent_itemsets = dict(frequent_1_itemsets)
    current_itemsets = list(frequent_1_itemsets.keys())
    k = 2
    
    while current_itemsets:
        # step 2: generate candidates of size k
        candidates = set()
        for i in range(len(current_itemsets)):
            for j in range(i + 1, len(current_itemsets)):
                # combine itemsets if they share k-2 elements
                union_set = current_itemsets[i] | current_itemsets[j]
                if len(union_set) == k:
                    candidates.add(union_set)
                    
        # step 3: count support for candidates
        candidate_counts = {candidate: 0 for candidate in candidates}
        for transaction in transactions:
            transaction_set = set(transaction)
            for candidate in candidates:
                if candidate.issubset(transaction_set):
                    candidate_counts[candidate] += 1
                    
        # step 4: filter candidates based on min support
        current_itemsets = []
        for candidate, count in candidate_counts.items():
            support = count / total_transactions
            if support >= min_support:
                current_itemsets.append(candidate)
                all_frequent_itemsets[candidate] = support
                
        k += 1
        
    return all_frequent_itemsets

def generate_rules(frequent_itemsets, min_confidence):
    # step 5: generate association rules from frequent itemsets
    rules = []
    for itemset, support in frequent_itemsets.items():
        if len(itemset) > 1:
            for i in range(1, len(itemset)):
                # generate all possible antecedents
                for antecedent in combinations(itemset, i):
                    antecedent = frozenset(antecedent)
                    consequent = itemset - antecedent
                    
                    # calculate confidence
                    antecedent_support = frequent_itemsets[antecedent]
                    confidence = support / antecedent_support
                    
                    if confidence >= min_confidence:
                        rules.append((antecedent, consequent, support, confidence))
                        
    return rules

def main():
    # sample transaction data
    transactions = [
        ['milk', 'bread', 'butter'],
        ['milk', 'bread'],
        ['milk', 'butter', 'eggs'],
        ['bread', 'butter', 'eggs'],
        ['milk', 'bread', 'butter', 'eggs']
    ]
    
    min_support = 0.4
    min_confidence = 0.6
    
    # run apriori
    frequent_itemsets = get_frequent_itemsets(transactions, min_support)
    rules = generate_rules(frequent_itemsets, min_confidence)
    
    # display results
    print("frequent itemsets:")
    for itemset, support in frequent_itemsets.items():
        print(f"{set(itemset)}: support = {support:.2f}")
        
    print("\nassociation rules:")
    for rule in rules:
        antecedent, consequent, support, confidence = rule
        print(f"{set(antecedent)} -> {set(consequent)}: support = {support:.2f}, confidence = {confidence:.2f}")

if __name__ == "__main__":
    main()
