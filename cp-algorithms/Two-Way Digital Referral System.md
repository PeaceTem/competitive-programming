
---

# ✅ **MASTER DEVELOPMENT CHECKLIST (PAGE-BY-PAGE)**

**For the Two-Way Digital Referral System (PHC, SHF, Admin)**

---

# 🔐 **1. AUTHENTICATION MODULE**

---

## **1. Login Page**

### **UI Tasks**

- Email/username field `DONE`
    
- Password field `DONE`
    
- "Show password" toggle `DONE`
    
- Login button `DONE`
    
- Offline indicator (“You are offline — Login unavailable”)
    
- Error display component `DONE`
    
- Link to "Forgot Password" `DONE`
    

### **Frontend Logic Tasks**

- Form validation `DONE`
    
- Handle login request `DONE`
    
- Store token (JWT) securely `DONE`
    
- Redirect based on role (PHC/SHF/Admin) `DONE`
    
- Save login state to localStorage `DONE`
    
- Disable login when offline `DONE`
    

### **Backend Tasks**

- Login endpoint
    

### **Offline Handling**

- Detect offline state
    
- Show offline banner
    

---

## **2. Register Account Page**

### **UI**

- First/last name
    
- Email `DONE`
    
- Phone
    
- Role dropdown `DONE`
    
- Facility dropdown `DONE`
    
- Submit button `DONE`
    
- “Awaiting approval” message
    

### **Frontend**

- Validate inputs `DONE`
    
- Send registration request `DONE`
    
- Load facilities list `DONE`
    
- Redirect to "Registration Submitted" page
    

### **Backend**

- Create user request `DONE`
    
- Queue for Admin approval
    
- Email notification (optional)
    

---

## **3. Forgot Password Page**

### **UI**

- Email input
    
- Submit button
    
- Reset success alert
    

### **Frontend**

- Basic validation
    
- Send request
    
- Display confirmation
    

### **Backend**

- Send reset link
    
- Reset password endpoint
    

---

# 🏥 **2. PHC MODULE**

---

## **4. PHC Dashboard**

### **UI**

- Cards for:
    
    - Pending referrals count
        
    - Approved referrals count
        
    - Feedback received
        
    - Reverse referrals
        
- Facility presence indicator
    
- Sync status icon
    
- Quick links
    

### **Frontend**

- Fetch dashboard stats
    
- Poll for updates
    
- Pull facility presence from backend
    

---

## **5. Create Referral Page**

### **UI**

- Patient information form
    
- Clinical details form
    
- SHF selection (show online/offline)
    
- Submit button
    
- Save as draft button
    
- Sync status
    
- Form validation errors
    

### **Frontend Logic**

- Validate all fields
    
- Auto-save as draft
    
- Save to IndexedDB when offline
    
- Onsubmit:
    
    - If online → send to API
        
    - If offline → mark as “pending sync”
        

### **Backend**

- Referral creation endpoint
    
- Validate patient object
    
- Return referral ID
    

### **Offline**

- Local storage schema
    
- Queue unsent referrals
    
- Sync worker
    

---

## **6. PHC Referral List Page**

### **UI**

- Tabs:
    
    - Pending
        
    - Approved
        
    - Rejected
        
    - Completed
        
    - Reverse referrals
        
- Filters:
    
    - Date range
        
    - Facility
        
    - Status
        
- Referral table
    

### **Frontend**

- Fetch referrals
    
- Implement pagination
    
- Handle offline mode (load from IndexedDB)
    
- Status mapping
    

---

## **7. Referral Details Page**

### **UI**

- Full summary (patient + clinical + facility)
    
- Status timeline
    
- Feedback section
    
- Sync status icon
    
- Referral history
    

### **Frontend**

- Fetch referral by ID
    
- Show feedback
    
- If offline → load from IndexedDB
    

---

## **8. Feedback Inbox Page**

### **UI**

- List of feedback entries
    
- Mark-as-read icon
    
- Filter by date
    

### **Frontend**

- Fetch feedback
    
- Local caching
    
- Display “New” badge
    

---

# 🏥 **3. SHF MODULE**

---

## **9. SHF Dashboard**

### **UI**

- Incoming referrals count
    
- Today appointments
    
- Presence indicator
    
- Notifications list
    

### **Frontend**

- Poll incoming referral count
    
- Fetch facility presence
    
- Load notifications
    

---

## **10. Incoming Referrals Page**

### **UI**

- List of referrals
    
- Quick actions:
    
    - Approve
        
    - Reject
        
- Filter by urgency
    

### **Frontend**

- Fetch pending referrals
    
- Click → open details
    

---

## **11. Referral Review Page**

### **UI**

- Full referral details
    
- Approve form:
    
    - Comment
        
- Reject form:
    
    - Reason
        
- Submit button
    

### **Frontend**

- Submit approval/rejection
    
- Local caching (optional)
    

### **Backend**

- Approval endpoint
    
- Rejection endpoint
    
- Update referral status
    

---

## **12. Provide Feedback Page**

### **UI**

- Diagnosis summary field
    
- Treatment notes
    
- Follow-up instructions
    
- Submit button
    

### **Frontend**

- Validate input
    
- Send feedback update
    

### **Backend**

- Create feedback record
    
- Attach to referral
    

---

## **13. Reverse Referral Page**

### **UI**

- Select PHC
    
- Add instructions
    
- Submit button
    

### **Backend**

- Reverse referral endpoint
    

---

# 🏛️ **4. ADMIN MODULE**

---

## **14. Admin Dashboard**

### **UI**

- Charts:
    
    - Monthly referrals
        
    - SHF load
        
    - PHC → SHF patterns
        
- Facility presence overview
    
- User activity logs
    

### **Backend**

- Stats endpoint
    
- Aggregated reporting
    

---

## **15. Facility Management Page**

### **UI**

- List of facilities
    
- Add new facility form
    
- Edit facility page
    
- Toggle active/inactive
    

### **Frontend**

- CRUD operations
    
- Validate inputs
    

### **Backend**

- Facilities table CRUD
    

---

## **16. User Management Page**

### **UI**

- List of users
    
- Approve registration
    
- Change role
    
- Reset password
    
- Activate / deactivate
    

### **Backend**

- User CRUD endpoints
    
- Approval API
    

---

## **17. Analytics & Reporting Page**

### **UI**

- Filters:
    
    - Facility
        
    - Time range
        
    - Status
        
- Charts + tables
    
- Export button (CSV/PDF)
    

### **Backend**

- Aggregated queries
    
- CSV export endpoint
    

---

## **18. System Activity Log Page**

### **UI**

- Table of:
    
    - User
        
    - Action
        
    - Timestamp
        
    - Referral ID
        
- Filter by user/date/action
    

### **Backend**

- Logs endpoint (paginated)
    

---

# 🔄 **5. SHARED PAGES**

---

## **19. Notifications Page**

### **UI**

- List of notifications
    
- Categories
    
- Mark as read
    

### **Frontend**

- Real-time listener (Phoenix channels optional)
    

---

## **20. Profile Settings Page**

### **UI**

- Update name
    
- Change password
    
- Change contact info
    

### **Backend**

- Update profile endpoint
    

---

## **21. Help & Support Page**

### **UI**

- FAQ
    
- Quick guides
    
- Contact form
    

---

## **22. Error & Offline Pages**

### **UI**

- 404 page
    
- 500 page
    
- “Offline — please reconnect”
    
- "Sync conflict detected" modal
    

### **Logic**

- Global error catcher
    
- Sync conflict resolver
    

---

# ⭐ **BONUS: CROSS-CUTTING SYSTEM-WIDE TASKS**

These are not pages but required for the system to function:

### **A. IndexedDB Schema**

- Users
    
- Referrals
    
- Feedback
    
- Sync queue
    

### **B. Sync Service Worker**

- Retry logic
    
- Conflict resolution
    
- ID mapping
    

### **C. Presence Module**

- Poll presence every X seconds
    
- Display online/offline badge
    

### **D. Role-Based Routing**

- Protect pages by role
    
- Redirect unauthorized access
    

### **E. Global UI Components**

- Navbar
    
- Sidebar
    
- Toast notifications
    
- Skeleton loaders