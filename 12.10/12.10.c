#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdlib.h>
//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
//
//////struct ListNode* deleteDuplicates(struct ListNode* head) {
//////    if (head == NULL)
//////        return head;
//////    struct ListNode* pre = head->next;
//////    struct ListNode* cur = head;
//////    while (pre)
//////    {
//////        if (pre->val != cur->val)
//////        {
//////            cur = pre;
//////            pre = pre->next;
//////        }
//////        else
//////        {
//////            if (pre->next == NULL)
//////            {
//////                if (cur == head)
//////                {
//////                    return NULL;
//////                }
//////                else
//////                {
//////                    free(pre);
//////                    struct ListNode* find = head;
//////                    while (find->next != cur)
//////                    {
//////                        find = find->next;
//////                    }
//////                    find->next = NULL;
//////                    free(cur);
//////                    break;
//////                }
//////            }
//////            while (pre->next->val == cur->val)
//////            {
//////                cur->next = pre->next;
//////                free(pre);
//////                pre = cur->next;
//////                if (pre->next == NULL)
//////                {
//////                    if (cur == head)
//////                    {
//////                        return NULL;
//////                    }
//////                    else
//////                    {
//////                        free(pre);
//////                        struct ListNode* find = head;
//////                        while (find->next != cur)
//////                        {
//////                            find = find->next;
//////                        }
//////                        find->next = NULL;
//////                        free(cur);
//////                        return head;
//////                    }
//////                }
//////            }
//////
//////
//////
//////            if (cur == head)
//////            {
//////                head = pre->next;
//////                free(cur);
//////                free(pre);
//////                cur = head;
//////                pre = head->next;
//////            }
//////            else {
//////                struct ListNode* next = pre->next;
//////                struct ListNode* find = head;
//////                while (find->next != cur)
//////                {
//////                    find = find->next;
//////                }
//////                find->next = next;
//////                free(cur);
//////                free(pre);
//////                cur = next;
//////                pre = next->next;
//////
//////            }
//////        }
//////    }
//////    return head;
////
////struct ListNode* deleteDuplicates(struct ListNode* head) {
////    if (head == NULL || head->next == NULL)
////    {
////        return head;
////    }
////    struct ListNode* pre = head->next;
////    struct ListNode* cur = head;
////    while (pre &&  pre->next != NULL)
////    {
////        if (head->val == pre->val)
////        {
////            struct ListNode* next = pre;
////            while (next->val == head->val)
////            {
////                next = next->next;
////                if (next->next->val = NULL)
////                    //return NULL;
////                    //break;
////                    continue;
////                //...
////            }
////            head = next;
////            continue;
////        }
////    }
////    return head;
////}
////
////
////struct ListNode* deleteDuplicates(struct ListNode* head)
////{
////    if (head == NULL || head->next == NULL)
////        return head;
////    struct ListNode* pre = head->next;
////    struct ListNode* cur = head;
////    struct ListNode * phead = NULL;
////    while (pre)
////    {
////        if (pre->val == cur->val)
////        {
////            while (pre->val == cur->val)
////            {
////                pre = pre->next;
////                cur->next = pre;
////                if (pre == NULL)
////                {
////                    if (phead == NULL)
////                        return NULL;
////                    else
////                    {
////                        phead->next = NULL;
////                        return head;
////                    }
////                }
////            }
////            if (phead == NULL)
////            {
////                head = pre;
////                cur = pre;
////                pre = pre->next;
////            }
////        else
////        {
////            phead->next = pre;
////            cur = pre;
////            pre = pre->next;
////        }
////        }
////        else
////        {
////            phead = cur;
////            cur = pre;
////            pre = pre->next;
////        }
////
////    }
////    return head;
////}
//
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdlib.h>
//
//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
//
////struct ListNode* deleteDuplicates(struct ListNode* head) {
////    if (head == NULL)
////        return head;
////    struct ListNode* pre = head->next;
////    struct ListNode* cur = head;
////    while (pre)
////    {
////        if (pre->val != cur->val)
////        {
////            cur = pre;
////            pre = pre->next;
////        }
////        else
////        {
////            if (pre->next == NULL)
////            {
////                if (cur == head)
////                {
////                    return NULL;
////                }
////                else
////                {
////                    free(pre);
////                    struct ListNode* find = head;
////                    while (find->next != cur)
////                    {
////                        find = find->next;
////                    }
////                    find->next = NULL;
////                    free(cur);
////                    break;
////                }
////            }
////            while (pre->next->val == cur->val)
////            {
////                cur->next = pre->next;
////                free(pre);
////                pre = cur->next;
////                if (pre->next == NULL)
////                {
////                    if (cur == head)
////                    {
////                        return NULL;
////                    }
////                    else
////                    {
////                        free(pre);
////                        struct ListNode* find = head;
////                        while (find->next != cur)
////                        {
////                            find = find->next;
////                        }
////                        find->next = NULL;
////                        free(cur);
////                        return head;
////                    }
////                }
////            }
////
////
////
////            if (cur == head)
////            {
////                head = pre->next;
////                free(cur);
////                free(pre);
////                cur = head;
////                pre = head->next;
////            }
////            else {
////                struct ListNode* next = pre->next;
////                struct ListNode* find = head;
////                while (find->next != cur)
////                {
////                    find = find->next;
////                }
////                find->next = next;
////                free(cur);
////                free(pre);
////                cur = next;
////                pre = next->next;
////
////            }
////        }
////    }
////    return head;
//
//struct ListNode* deleteDuplicates(struct ListNode* head) {
//    if (head == NULL || head->next == NULL)
//    {
//        return head;
//    }
//    struct ListNode* pre = head->next;
//    struct ListNode* cur = head;
//    while (pre && pre->next != NULL)
//    {
//        if (head->val == pre->val)
//        {
//            struct ListNode* next = pre;
//            while (next->val == head->val)
//            {
//                next = next->next;
//                if (next->next->val = NULL)
//                    //return NULL;
//                    //break;
//                    continue;
//                //...
//            }
//            head = next;
//            continue;
//        }
//    }
//    return head;
//}
//
//
//struct ListNode* deleteDuplicates(struct ListNode* head)
//{
//    if (head == NULL || head->next == NULL)
//        return head;
//    struct ListNode* pre = head->next;
//    struct ListNode* cur = head;
//    struct ListNode* phead = NULL;
//    while (pre)
//    {
//        if (pre->val == cur->val)
//        {
//            while (pre->val == cur->val)
//            {
//                pre = pre->next;
//                cur->next = pre;
//                if (pre == NULL)
//                {
//                    if (phead == NULL)
//                        return NULL;
//                    else
//                    {
//                        phead->next = NULL;
//                        return head;
//                    }
//                }
//            }
//            if (phead == NULL)
//            {
//                head = pre;
//                cur = pre;
//                pre = pre->next;
//            }
//            else
//            {
//                phead->next = pre;
//                cur = pre;
//                pre = pre->next;
//            }
//        }
//        else
//        {
//            phead = cur;
//            cur = pre;
//            pre = pre->next;
//        }
//
//    }
//    return head;
//}


