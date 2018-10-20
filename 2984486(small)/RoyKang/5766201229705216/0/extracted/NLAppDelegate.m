//
//  NLAppDelegate.m
//  GCJO
//
//  Created by LinePlus on 2014. 4. 26..
//  Copyright (c) 2014년 LINE. All rights reserved.
//

#import "NLAppDelegate.h"

#define N 2000

FILE *fin, *fout;
int testCases;
int n;
int edge[N][2];
int saved[N];

void deleteAllOfNode(int node)
{
    for(int i=0;i<n;i++) {
        if(edge[i][0] == node) {
            edge[i][0] = edge[i][1] = -1;
            deleteAllOfNode(node);
        }
        else if(edge[i][1] == node) {
            edge[i][1] = edge[i][0] = -1;
            deleteAllOfNode(node);
        }
    }
}

void testCase(int testCase)
{
    fscanf(fin, " %d", &n);
    for(int i=0;i<n-1;i++) {
        fscanf(fin, " %d %d", &edge[i][0], &edge[i][1]);
    }
    
    for(int i=0;i<n;i++) {
        saved[0] = 0;
    }

    NSMutableArray *numbersToCheck = [[NSMutableArray alloc] init];
    [numbersToCheck addObject:@(1)];
    
    int leftChild, rightChild;
    int numOfCut = 0;

    for(int count=0;count<n;count++) {
        if(numbersToCheck.count < 1) {
            break;
        }
        NSNumber *numberToCheck = [numbersToCheck objectAtIndex:0];
        int currentNode = [numberToCheck intValue];
        [numbersToCheck removeObjectAtIndex:0];

        leftChild = rightChild = -1;
        
        for(int i=0;i<n;i++) {
            int childNode = -1;
            if(edge[i][0] == currentNode) {
                childNode = edge[i][1];
            }
            else if (edge[i][1] == currentNode) {                
                childNode = edge[i][0];
            }
            if(childNode != -1) {
                if(leftChild == -1) {
                    leftChild = childNode;
                    edge[i][0] = -1;
                    edge[i][1] = -1;
                }
                else if(rightChild == -1) {
                    rightChild = childNode;
                    edge[i][0] = -1;
                    edge[i][1] = -1;
                }
            }
        }
        
        if((leftChild != -1 && rightChild == -1) || (leftChild == -1 && rightChild != -1)) {
            numOfCut++;
            
            if(leftChild != -1) {
                deleteAllOfNode(leftChild);
            }
            else if(rightChild != -1) {
                deleteAllOfNode(rightChild);
            }
        }
        else if (leftChild != -1 && rightChild != -1) {
            [numbersToCheck addObject:@(leftChild)];
            [numbersToCheck addObject:@(rightChild)];
        }
    }
    
    fprintf(fout, "Case #%d: %d", testCase, numOfCut);
    if(testCase < testCases) {
        fprintf(fout, "\n");
    }
}

@implementation NLAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    fin = fopen("/Users/lineplus/Desktop/data.in", "r");
    fout = fopen("/Users/lineplus/Desktop/data.out", "w");
    
    fscanf(fin, " %d", &testCases);
    
    for(int i=1;i<=testCases;i++) {
        testCase(i);
    }
    
    fclose(fin);
    fclose(fout);
    
    return YES;
}

@end
