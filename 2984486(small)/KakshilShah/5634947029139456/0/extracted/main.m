//
//  main.m
//  Code
//
//  Created by Kakshil Shah on 19/04/14.
//  Copyright (c) 2014 BazingaLabs. All rights reserved.
//

#import <Foundation/Foundation.h>


#import "NSArray+EKStuff.h"
#import "NSArray+EKSorting.h"
#import "NSNumber+EKStuff.h"
#import "NSString+EKStuff.h"
#import "EKStack.h"
#import "EKQueue.h"
#import "EKDeque.h"
#import "EKBHeap.h"
#import "EKVertex.h"
#import "EKGraph.h"
#import "EKEdge.h"
#import "EKLinkedList.h"
#import "EKNode.h"
#import "EKBSTree.h"
#import "EKAVLTree.h"
#import "EKTree.h"
#import "EKBTree.h"
#import "EKRecursionStuff.h"

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define MP          make_pair
typedef long long   LL;

char mapa[300];

@interface ClassSolve:NSObject{
}
@property (nonatomic,strong) NSMutableArray *currentArray;
@property (nonatomic,strong) NSMutableArray *requiredArray;
@property (nonatomic,strong) NSMutableArray *ansArray;
-(NSString *) calculate : (NSArray *) data;
@end

@implementation ClassSolve
-(id) init {
    self = [super init];
    
    return self;
}

/*
private static void subsetsRest(char[] e, boolean[] isIn, int iStart) {
    /*
     e is the array of possible characters.
     e[j] is in the set if isIn[j] is true, for each j < iStart.
     isIn[j] is false for each j >= iStart.
     isIn ends in the same state it starts the method.
     The method provides all choices of true and false values for every
     index >= iStart, and prints the result if iStart == e.length.
 
    
    if (iStart == e.length) {
        for (int j = 0; j < e.length; j++)
            if(isIn[j]) System.out.print(e[j]);
        System.out.println();
    }
    else {
        isIn[iStart] = true;
        subsetsRest(e, isIn, iStart+1);  // do include e[iStart]
        isIn[iStart] = false; // placing isIn back in its original state
        subsetsRest(e, isIn, iStart+1);  // not include e[iStart]
    } 
}

*/




-(BOOL) checkArray:(NSMutableArray *) first WithArray:(NSMutableArray *) second
{
    
    
    BOOL ans = TRUE;
    
    bool sb[second.count];
    
    for (int  i = 0; i<second.count; i++) {
        sb[i] = true;
    }
    
    
    
    for (int i = 0; i<first.count; i++) {
        bool found = 0;
        for (int j = 0; j<first.count; j++) {
            
            NSString *firstElem = [first objectAtIndex:i];
            
            NSString *secondElem = [second objectAtIndex:j];
            
            if ([firstElem isEqualToString:secondElem] && sb[j]) {
                found = 1;
                sb[j] = false;
            }
            
            
        }
        
        if (found == 0) {
            ans = FALSE;
        }
        
        
    }
    
    return ans;
}


-(void) swapFromBool:(bool []) b length:(int ) l current:(int) c
{
    NSMutableArray *dup = [self.currentArray mutableCopy];
    int count = 0;
    for (int i =0; i<l; i++) {
        if (b[i] == true) {
         //swap the bits
            
            count++;
            //swap
            
            
            
           
            
            
            for (int k = 0; k<dup.count; k++) {
                
                
                NSString *item = [dup objectAtIndex:k];
                
                
                
                NSString *element = [item substringWithRange:NSMakeRange(i, 1)];
                
                NSString *replace = @"1";
                
                if ([element isEqualToString:@"1"]) {
                    replace = @"0";
                }
                
                
               NSString *newItem =  [item stringByReplacingCharactersInRange:NSMakeRange(i, 1) withString:replace];
                
                //replace the bit at index i
                
                
            //    [dup replaceObjectAtIndex:k withObject:newItem];
                
                [dup replaceObjectAtIndex:k withObject:newItem];
                
            }
            
  
            
            
        }
    }
    
    if([self checkArray:dup WithArray:self.requiredArray])
    {
        int val = [[self.ansArray objectAtIndex:c] intValue];
        if (val == -1) {
            val = count;
        }
        else if(val>count)
        {
            val = count;
        }
        [self.ansArray replaceObjectAtIndex:c withObject:[NSNumber numberWithInt:val]];
    }
}


-(void) subsetsBool:(bool[]) b start:(int) start length:(int)l current:(int) c
{
    if (start == l) {
        [self swapFromBool:b length:l current:c];
    }
    else {
        b[start] = true;
       // subsetsRest(e, isIn, iStart+1);  // do include e[iStart]
        
        [self subsetsBool:b start:start+1 length:l current:c];
        
        b[start] = false; // placing isIn back in its original state
     ///   subsetsRest(e, isIn, iStart+1);  // not include e[iStart]
        
        [self subsetsBool:b start:start+1 length:l current:c];
    }

}


-(NSString *) calculate : (NSArray *) data
{
    NSMutableString *output = [@"" mutableCopy];
    int lines = [[data objectAtIndex:0] intValue];
    int present = 1;
    
    self.ansArray = [[NSMutableArray alloc] init];
    for (int i = 0; i<lines; i++) {
        [self.ansArray addObject:@-1];
    }
    
    
    
        F(dumm,lines) {
        NSString *values = [data objectAtIndex:present] ;
            present++;
            NSString *current = [data objectAtIndex:present] ;
            present++;
            NSString *required = [data objectAtIndex:present] ;
            present++;

        
        NSArray* valuesArray =
        [values componentsSeparatedByCharactersInSet:
         [NSCharacterSet whitespaceCharacterSet]];
            
            
           self.currentArray =
            [[current componentsSeparatedByCharactersInSet:
             [NSCharacterSet whitespaceCharacterSet]] mutableCopy];
            
             self.requiredArray =
            [[required componentsSeparatedByCharactersInSet:
             [NSCharacterSet whitespaceCharacterSet]] mutableCopy];
            
            
            
            
            int number = [[valuesArray objectAtIndex:0] intValue];
            
            int length = [[valuesArray objectAtIndex:1] intValue];
            
            
            bool b[length];// = new bool[length];
            
            
            [self subsetsBool:b start:0 length:length current:dumm];
            
            
            
            
            
            
            
            
            
            
            id outp = [self.ansArray objectAtIndex:dumm];
            
            NSString *outs;
            
            if ([outp  isEqual: @-1]) {
                outs = @"NOT POSSIBLE";
            }
            else
            {
                outs = [NSString stringWithFormat:@"%@",outp];
            }
            
            
        [output appendString:[NSString stringWithFormat:@"Case #%i: %@\n",(dumm+1),outs]];
    }
    return output;
}

@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        freopen("/Users/Apple/Desktop/out.txt", "w", stdout);
        NSString* fileRoot = @"/Users/Apple/Desktop/in.txt";

        NSString* fileContents =
        [NSString stringWithContentsOfFile:fileRoot
                                  encoding:NSUTF8StringEncoding error:nil];

        NSArray* allLinedStrings =
        [fileContents componentsSeparatedByCharactersInSet:
         [NSCharacterSet newlineCharacterSet]];
        
        
        
        
        
        ClassSolve *class = [[ClassSolve alloc] init];
        
           printf("%s",[[class calculate:allLinedStrings] UTF8String]);

    }
    return 0;
}



