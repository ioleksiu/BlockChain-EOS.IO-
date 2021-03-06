const char* tutor_wast = R"=====(
(module
 (type $FUNCSIG$vi (func (param i32)))
 (type $FUNCSIG$vj (func (param i64)))
 (type $FUNCSIG$iii (func (param i32 i32) (result i32)))
 (type $FUNCSIG$vii (func (param i32 i32)))
 (import "env" "assert" (func $assert (param i32 i32)))
 (import "env" "printi" (func $printi (param i64)))
 (import "env" "printn" (func $printn (param i64)))
 (import "env" "prints" (func $prints (param i32)))
 (import "env" "readMessage" (func $readMessage (param i32 i32) (result i32)))
 (import "env" "requireAuth" (func $requireAuth (param i64)))
 (table 0 anyfunc)
 (memory $0 1)
 (data (i32.const 4) "\e0@\00\00")
 (data (i32.const 16) "Init World!\n\00")
 (data (i32.const 32) "Hello World: \00")
 (data (i32.const 48) "->\00")
 (data (i32.const 64) "\n\00")
 (data (i32.const 80) "transfer\00")
 (data (i32.const 96) "message shorter than expected\00")
 (data (i32.const 128) "Must transfer an amount greater than 0\00")
 (data (i32.const 176) "Transfer \00")
 (data (i32.const 192) " from \00")
 (data (i32.const 208) " to \00")
 (export "memory" (memory $0))
 (export "init" (func $init))
 (export "apply" (func $apply))
 (func $init
  (call $prints
   (i32.const 16)
  )
 )
 (func $apply (param $0 i64) (param $1 i64)
  (local $2 i32)
  (local $3 i32)
  (local $4 i64)
  (local $5 i64)
  (local $6 i64)
  (local $7 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $7
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (call $prints
   (i32.const 32)
  )
  (call $printn
   (get_local $0)
  )
  (call $prints
   (i32.const 48)
  )
  (call $printn
   (get_local $1)
  )
  (call $prints
   (i32.const 64)
  )
  (set_local $0
   (i64.const 0)
  )
  (set_local $4
   (i64.const 59)
  )
  (set_local $3
   (i32.const 80)
  )
  (set_local $5
   (i64.const 0)
  )
  (loop $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (block $label$5
        (br_if $label$5
         (i64.gt_u
          (get_local $0)
          (i64.const 7)
         )
        )
        (br_if $label$4
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $2
             (i32.load8_s
              (get_local $3)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $2
         (i32.add
          (get_local $2)
          (i32.const 165)
         )
        )
        (br $label$3)
       )
       (set_local $6
        (i64.const 0)
       )
       (br_if $label$2
        (i64.le_u
         (get_local $0)
         (i64.const 11)
        )
       )
       (br $label$1)
      )
      (set_local $2
       (select
        (i32.add
         (get_local $2)
         (i32.const 208)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $2)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $6
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $2)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $6
     (i64.shl
      (i64.and
       (get_local $6)
       (i64.const 31)
      )
      (i64.and
       (get_local $4)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $3
    (i32.add
     (get_local $3)
     (i32.const 1)
    )
   )
   (set_local $0
    (i64.add
     (get_local $0)
     (i64.const 1)
    )
   )
   (set_local $5
    (i64.or
     (get_local $6)
     (get_local $5)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $4
      (i64.add
       (get_local $4)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (block $label$6
   (br_if $label$6
    (i64.ne
     (get_local $5)
     (get_local $1)
    )
   )
   (call $assert
    (i32.gt_u
     (call $readMessage
      (i32.add
       (get_local $7)
       (i32.const 8)
      )
      (i32.const 24)
     )
     (i32.const 23)
    )
    (i32.const 96)
   )
   (call $assert
    (i64.ne
     (i64.load offset=24
      (get_local $7)
     )
     (i64.const 0)
    )
    (i32.const 128)
   )
   (call $requireAuth
    (i64.load offset=8
     (get_local $7)
    )
   )
   (set_local $0
    (i64.load offset=16
     (get_local $7)
    )
   )
   (set_local $6
    (i64.load offset=8
     (get_local $7)
    )
   )
   (set_local $4
    (i64.load offset=24
     (get_local $7)
    )
   )
   (call $prints
    (i32.const 176)
   )
   (call $printi
    (get_local $4)
   )
   (call $prints
    (i32.const 192)
   )
   (call $printi
    (get_local $6)
   )
   (call $prints
    (i32.const 208)
   )
   (call $printi
    (get_local $0)
   )
   (call $prints
    (i32.const 64)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $7)
    (i32.const 32)
   )
  )
 )
)
)=====";
