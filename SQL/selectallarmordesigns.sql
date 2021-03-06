/****** Script for SelectTopNRows command from SSMS  ******/

SELECT ItemNum, Kind, SourceIndex, ItemName, AbilityMin, AbilityMax, HitRate, ShotNum, MultiNum, ReqUnitKind, '(not tested)'
FROM ti_ItemInfo
WHERE ItemNum IN (
	SELECT (
		SELECT TOP 1 b.ItemNum
		FROM ti_ItemInfo b
		WHERE a.SourceIndex = b.SourceIndex and a.ShotNum = b.ShotNum and a.MultiNum = b.MultiNum
		ORDER BY b.ReqMinLevel desc
	)
	FROM ti_ItemInfo a
	WHERE Kind < 16
GROUP BY SourceIndex, ShotNum, MultiNum
)
ORDER BY ReqUnitKind, Kind, ShotNum, MultiNum